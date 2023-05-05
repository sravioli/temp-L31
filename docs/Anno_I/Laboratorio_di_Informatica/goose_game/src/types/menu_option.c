// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "./menu_option.h"

MenuOption *init_option() {
  return (MenuOption *)malloc(sizeof(MenuOption));  // NOLINT
}

char get_key(MenuOption option) { return option.key; }
void set_key(MenuOption *option, char key) { option->key = key; }

char *get_text(MenuOption option) {
  static char text[MAX_LINE_LEN + 1];
  snprintf(text, sizeof(text), "%s", option.text);
  return text;
}
void set_text(MenuOption *option, char text[]) {
  snprintf(option->text, sizeof(option->text), "%s", text);
}

void (*get_action(MenuOption option))() { return option.action; }
void set_action(MenuOption *option, void (*action)()) {
  option->action = action;
}
