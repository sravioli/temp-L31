#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMS 100
#define MAX_BINARY_DIGITS 20
#define BUFFER_SIZE (MAX_BINARY_DIGITS + 1)

typedef struct Numbers {
  int values[MAX_NUMS];
  int dim;
} Numbers;

// access functions
void set_dimension(Numbers *nums, int dim) { nums->dim = dim; }
const int get_dimension(const Numbers *nums) { return nums->dim; }

void set_value(Numbers *nums, int index, int value) {
  nums->values[index] = value;
}
const int get_value(Numbers *nums, int index) { return nums->values[index]; }

int sum_numbers(Numbers numeri) {
  int somma = 0;
  int i = 0;
  while (i < get_dimension(&numeri)) {
    somma += get_value(&numeri, i);
    i = i + 1;
  }
  return somma;
}

// read binary numbers from a file and store them in the Numbers struct
int read_binary_numbers_from_file_and_sum(const char *filename, Numbers *nums) {
  // safe open file
  FILE *fp;
  if (fopen_s(&fp, filename, "r")) {
    printf("Failed to open the fp: %s\n", filename);
    return -1;
  }

  char buffer[BUFFER_SIZE];
  int index = 0;
  while (fscanf_s(fp, "%s", buffer, sizeof(buffer)) == 1) {
    set_value(nums, index, strtol(buffer, NULL, 2));
    index = index + 1;
  }
  fclose(fp);

  // set the dimension of the Numbers struct
  set_dimension(nums, index);

  return sum_numbers(*nums);
}

int main() {
  Numbers nums;
  int ret = read_binary_numbers_from_file_and_sum("file.txt", &nums);
  // int ret = read_binary_numbers_from_file_and_sum("filevuoto.txt", &nums);
  printf("sum result = %i\n", ret);

  // Print the values
  // int i = 0;
  // while (i < get_dimension(&nums)) {
  //   printf("Value at index %d: %d\n", i, get_value(&nums, i));
  //   i = i + 1;
  // }

  return 0;
}
