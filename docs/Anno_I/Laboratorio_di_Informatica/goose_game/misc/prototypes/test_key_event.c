#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ENTRIES 10

struct menu_entry {
  char key;
  char text[256];
};

int main() {
  char menu_str[] = "[n]ew game\n[l]oad game\n[s]ave game\n[q]uit game\n";
  struct menu_entry menu[MAX_MENU_ENTRIES];
  int num_entries = 0;

  // Parse the menu entry string
  char *token = strtok(menu_str, "\n");
  while (token != NULL && num_entries < MAX_MENU_ENTRIES) {
    struct menu_entry entry;

    // Extract the key
    char *key_pos = strchr(token, '[');
    if (key_pos == NULL) {
      printf("Invalid menu entry: %s\n", token);
      return 1;
    }
    entry.key = key_pos[1];

    // Extract the text
    char *text_pos = strchr(token, ']');
    if (text_pos == NULL) {
      printf("Invalid menu entry: %s\n", token);
      return 1;
    }
    strcpy(entry.text, text_pos + 1);

    menu[num_entries++] = entry;

    token = strtok(NULL, "\n");
  }

  // Print the menu entries
  for (int i = 0; i < num_entries; i++) {
    printf("[%c]%s\n", menu[i].key, menu[i].text);
  }

  // Wait for user input
  int loop = 1;
  while (loop) {
    char input = _getch();

    // Find the corresponding menu entry
    for (int i = 0; i < num_entries; i++) {
      if (input == menu[i].key) {
        printf("Selected entry: %c%s\n", menu[i].key, menu[i].text);
        loop = 0;
        break;
      }
    }
  }

  return 0;
}
