// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "../inc/handle_leaderboard.h"

Entries *allocate_entries() {
  Entries *es = (Entries *)malloc(sizeof(Entries));  // NOLINT
  if (!es) {
    printf("error: failed to allocate memory for Entries struct.\n");
    exit(EXIT_FAILURE);
  }
  return es;
}

Entries read_entries(const char filename[]) {
  Entries *es = allocate_entries();

  // read struct from given file
  FILE *fp;
  if (fopen_s(&fp, filename, "rb") != 0) {
    printf("error: failed to open '%s'.\n", filename);
    exit(EXIT_FAILURE);
  }
  int num_read_entries = fread(es, sizeof(Entries), 1, fp);
  fclose(fp);

  if (num_read_entries != 1) {
    printf("error: failed to read Entreis struct from file\n");
    free(es);
    exit(EXIT_FAILURE);
  }

  return *es;
}
