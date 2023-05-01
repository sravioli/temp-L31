#include <stdio.h>

// Define a structure to represent a menu option
typedef struct {
  char key;
  char text[100];
} MenuOption;

int main() {
  // Create an array of MenuOption structures to represent the menu
  MenuOption menu[] = {{'n', "ew game"},
                       {'s', "aved games"},
                       {'l', "eaderboard"},
                       {'h', "elp"},
                       {'q', "uit"}};

  // Write the menu to a binary file
  FILE *file = fopen("menu.bin", "wb");
  fwrite(menu, sizeof(MenuOption), 5, file);
  fclose(file);

  return 0;
}
