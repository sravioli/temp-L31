#include <stdio.h>
#include <string.h>
#include <wchar.h>

#ifdef _WIN32
#include <Windows.h>

void get_term_size(int *width, int *height) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hConsole, &csbi);
  *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void clear_screen() { system("cls"); }

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

#elif __linux__ || __APPLE__
#include <sys/ioctl.h>
#include <unistd.h>
void get_term_size(int *width, int *height) {
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
  *width = ws.ws_col;
  *height = ws.ws_row;
}

void clear_screen() { printf("\033c"); }

void clear_line() { printf("\033[2K\r"); }
#else
#error Unsupported platform
#endif

void center_text(const char *text, int term_width, int term_height) {
  // Calculate center alignment
  int text_length = strlen(text);
  int horizontal_padding = (term_width - text_length) / 2;
  int vertical_padding = term_height / 2;

  // Print centered text
  for (int i = 0; i < vertical_padding; i++) {
    printf("\n");
  }
  for (int i = 0; i < horizontal_padding; i++) {
    printf(" ");
  }
  printf("%s\n", text);
}

void print_justified(const char *justification, const char *text,
                     int term_width) {
  int text_length = strlen(text);
  int remaining_space = term_width - text_length;

  if (remaining_space <= 0) {
    // If the term width is smaller than the text length, print text as is
    printf("%s", text);
  } else {
    if (strcmp(justification, "left") == 0) {
      // Left justification
      printf("%s", text);
    } else if (strcmp(justification, "right") == 0) {
      // Right justification
      for (int i = 0; i < remaining_space; i++) {
        putchar(' ');
      }
      printf("%s", text);
    } else if (strcmp(justification, "center") == 0) {
      // Center justification
      int left_space = remaining_space / 2;
      int right_space = remaining_space - left_space;
      for (int i = 0; i < left_space; i++) {
        putchar(' ');
      }
      printf("%s", text);
      for (int i = 0; i < right_space; i++) {
        putchar(' ');
      }
    } else {
      printf(
          "Invalid justification direction! Use 'left', 'right', or 'center'.");
    }
  }
}
