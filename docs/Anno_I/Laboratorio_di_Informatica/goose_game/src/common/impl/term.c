// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "../inc/term.h"

void throw_err(const char caller[], const char format[], ...) {
  char buffer[MAX_BUFFER_LEN];  // will recieve the error message

  // format the errror message into the buffer
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, sizeof(buffer), format, args);
  va_end(args);

  // print to stderr the error
  fprintf(stderr, THROW_FORMAT, YELLOW, caller, RED, buffer, RESET);
  exit(EXIT_FAILURE);  // terminate the program
}

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

void get_term_size(int *width, int *height) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hConsole, &csbi);
  *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void clear_screen() {
  HANDLE hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD count;
  DWORD cellCount;
  COORD homeCoords = {0, 0};

  hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hStdOut == INVALID_HANDLE_VALUE) {
    return;
  }

  // Get the number of cells in the current buffer
  if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
    return;
  }
  cellCount = csbi.dwSize.X * csbi.dwSize.Y;

  // Fill the entire buffer with spaces
  if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords,
                                  &count)) {
    return;
  }

  // Fill the entire buffer with the current colors and attributes
  if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount,
                                  homeCoords, &count)) {
    return;
  }

  // Move the cursor home
  SetConsoleCursorPosition(hStdOut, homeCoords);
}

void clear_line() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD coord;
  DWORD written;
  GetConsoleScreenBufferInfo(hConsole, &csbi);
  coord.X = 0;
  coord.Y = csbi.dwCursorPosition.Y;
  FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X, coord, &written);
  SetConsoleCursorPosition(hConsole, coord);
}

void new_screen() {
  clear_screen();

  int term_width, term_heigth;
  get_term_size(&term_width, &term_heigth);

  int left_space = 1 + (term_width - strlen(TITLE_BAR)) / 2;

  int i = 0;
  while (i < left_space) {
    printf("%c", SPACE_CHAR);
    i = i + 1;
  }
  printf(TITLE_BAR, BOLD, RESET, LINE_END);

  i = 0;
  while (i < term_width) {
    printf("-");
    i = i + 1;
  }

  printf("%s", LINE_END);
}

void print_menu(const char filename[]) {
  FILE *fp;
  if (fopen_s(&fp, filename, "r")) {
    throw_err(__func__, "failed to open file '%s' for reading", filename);
  }

  int width, height;
  get_term_size(&width, &height);

  // initialize 2D list to store menu entries
  char menu[MAX_MENU_LINES][MAX_BUFFER_LEN];
  char buffer[MAX_BUFFER_LEN];

  int num_lines = 0;  // count number of menu lines
  int max_len = 0;
  // read until EOF or when running out of space
  while (fgets(buffer, MAX_BUFFER_LEN, fp) && num_lines < MAX_MENU_LINES) {
    max_len = max(strlen(buffer), max_len);  // save the longest line

    // copy line to menu list
    snprintf(menu[num_lines], sizeof(buffer), "%s", buffer);
    num_lines = num_lines + 1;
  }
  fclose(fp);

  // print vertical padding
  int i = 0;
  int vert_padding = (height - num_lines - 2) * 0.45;
  while (i < vert_padding) {
    printf("%s", LINE_END);
    i = i + 1;
  }

  // print all menu entries with left padding (center them)
  i = 0;
  int left_padding = (width - max_len) / 2;
  while (i < num_lines) {
    int j = 0;
    while (j < left_padding) {
      printf("%c", SPACE_CHAR);
      j = j + 1;
    }
    printf("%s", menu[i]);
    i = i + 1;
  }

  printf("%s", LINE_END);
}

void print_file(const char filename[]) {
  FILE *fp;
  if (fopen_s(&fp, filename, "r")) {
    throw_err(__func__, "failed to open file '%s' for reading", filename);
  }

  int width, height;
  get_term_size(&width, &height);

  // read until EOF or when running out of space
  char buffer[MAX_BUFFER_LEN];
  int num_lines = 0;
  while (fgets(buffer, MAX_BUFFER_LEN, fp) && num_lines < MAX_FILE_LINES) {
    printf("%s", buffer);
    num_lines = num_lines + 1;
  }
  fclose(fp);
}

int is_back_key(const char key) {
  if (key == ESC || key == ENTER || key == SPACEBAR || key == 'b') {
    return TRUE;
  }
  return FALSE;
}

int is_quit_key(const char key) {
  if (key == ESC || key == 'q') {
    return TRUE;
  }
  return FALSE;
}

void wait_keypress(const char format[], ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);

  const char spinner[4] = {'|', '/', '-', '\\'};
  printf("%c%c", SPACE_CHAR, SPACE_CHAR);

  // display the spinner by printing the char and then deleting it
  int i = 0;
  while (!_kbhit()) {
    printf("\b");
    printf("%c", spinner[i % sizeof(spinner)]);
    i = i + 1;
    Sleep(100);
  }
  // consume the pressed key before continuing otherwise it will interfere when
  // getting user input.
  _getch();
}
