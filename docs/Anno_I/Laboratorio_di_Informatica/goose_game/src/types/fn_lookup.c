// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "./fn_lookup.h"

char get_fn_key(struct FnLookup functions[], const int index) {
  return functions[index].key;
}
void set_fn_key(struct FnLookup *functions, const char key) {
  functions->key = key;
}

void (*get_fn(struct FnLookup functions[], const int index))() {  // NOLINT
  return functions[index].fn;
}
void set_fn(struct FnLookup *functions, const int index, void (*fn)()) {
  functions->fn = fn;
}

int lookup_fn(struct FnLookup functions[], const int num_functions, char key) {
  // iterate over the number of functions present in the array
  int index = 0;
  while (index < num_functions) {
    // search for a match
    if (get_fn_key(functions, index) == key) {
      return index;  // return the matched index
    }
    index = index + 1;
  }
  printf("error: no function found for key '%c'\n", key);
  exit(EXIT_FAILURE);  // no match, terminate the program
}
