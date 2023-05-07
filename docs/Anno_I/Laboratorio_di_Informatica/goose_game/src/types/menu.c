// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "./menu.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

char *get_title(Menu menu) {
  static char new_title[MAX_LINE_LEN + 1];
  snprintf(new_title, sizeof(menu.title), "%s", menu.title);
  return new_title;
}
void set_title(Menu *menu, char title[]) {
  snprintf(menu->title, strlen(title), "%s", title);
}

MenuOption get_option(Menu menu, int index) { return menu.options[index]; }
void set_option(Menu *menu, int num_options, MenuOption option) {
  menu->options[num_options] = option;
}

char get_menu_key(Menu menu, const int index) {
  return get_key(get_option(menu, index));
}
char *get_menu_text(Menu menu, const int index) {
  return get_text(get_option(menu, index));
}

void call_action(Menu menu, const int index) { menu.options[index].action(); }

int get_num_options(Menu menu) { return menu.num_options; }
void set_num_options(Menu *menu, int num_options) {
  menu->num_options = num_options;
}
