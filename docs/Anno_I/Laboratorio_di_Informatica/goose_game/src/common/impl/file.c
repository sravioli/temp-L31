// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MenuOption {
  char key;
  char text[];
} MenuOption;

void read_menu(const char filename[]) {
  FILE *fp;
  if (!fp) {
    printf("error: failed to open file %s\n", filename);
    return;
  }

  fseek(fp, 0, SEEK_END);
  long fp_size = ftell(fp);  // NOLINT
  fseek(fp, 0, SEEK_SET);
  //
  // Allocate memory for the file contents
  char *buffer = (char *)malloc(fp_size + 1);  // NOLINT
  if (!buffer) {
    printf("error: failed toallocate memory.\n");
    fclose(fp);
    return;
  }

  // Read the file into the buffer
  fread(buffer, fp_size, 1, fp);

  // Null-terminate the buffer to make it a string
  buffer[fp_size] = '\0';
  fclose(fp);

  // Print the contents of the buffer
  printf("%s", buffer);

  // Free the memory allocated for the buffer
  free(buffer);
}

int main(void) {
  read_menu("main_menu.bin");
  return EXIT_SUCCESS;
}
