#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./core/term.h"

int main(void) {
  int width, height;
  get_term_size(&width, &height);
  clear_screen();
  printf("width = %d\n", width);
  printf("height = %d\n", height);
  printf("questo non deve apparire");
  clear_line();

  center_text("questo dovrebbe essere centrato", width, height);

  system("pause");
  clear_screen();

  const char *input_text = "This is a sample text to be justified";

  printf("Left Justified Text:\n");
  print_justified("left", input_text, width);
  printf("\n\n");

  printf("Right Justified Text:\n");
  print_justified("right", input_text, width);
  printf("\n\n");

  printf("Center Justified Text:\n");
  print_justified("center", input_text, width);
  printf("\n\n");

  system("pause");
  clear_screen();

  return 0;
}
