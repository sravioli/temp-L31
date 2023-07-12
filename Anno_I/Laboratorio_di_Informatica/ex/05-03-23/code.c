#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 15
#define MAX_COLS 10

typedef struct Matrix {
  int rows;
  int cols;
  int **data;
} Matrix;

// access functions
int get_cols(Matrix matrix) { return matrix.cols; }
void set_cols(Matrix *matrix, int cols) { matrix->cols = cols; }

int get_rows(Matrix matrix) { return matrix.rows; }
void set_rows(Matrix *matrix, int rows) { matrix->rows = rows; }

int *get_row(Matrix matrix, int index) { return matrix.data[index]; }
int *get_col(Matrix matrix, int index) {
  int *col = malloc(sizeof(int) * matrix.rows);
  for (int i = 0; i < matrix.rows; i++) {
    col[i] = matrix.data[i][index];
  }
  return col;
}

int get_value(Matrix matrix, int row, int col) { return matrix.data[row][col]; }
void set_value(Matrix *matrix, int value, int row, int col) {
  matrix->data[row][col] = value;
}

// allocate data for a single matrix
Matrix *create_matrix(int rows, int cols) {
  Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
  set_rows(matrix, rows);
  set_cols(matrix, cols);
  matrix->data = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = (int *)malloc(cols * sizeof(int));
  }
  return matrix;
}

// Function to free the memory used by a matrix
void destroy_matrix(Matrix *matrix) {
  for (int i = 0; i < get_rows(*matrix); i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

void destroy_matrices(Matrix *matrix, ...) {
  void *mtrx = matrix;

  va_list args;
  va_start(args, matrix);
  while (mtrx) {
    destroy_matrix(mtrx);
    mtrx = va_arg(args, void *);
  }
  va_end(args);
}

// Function to get the value at the given row and column in the matrix

void write_matrix(FILE *fp, Matrix *matrix) {
  fwrite(&matrix->rows, sizeof(get_rows(*matrix)), 1, fp);
  fwrite(&matrix->cols, sizeof(get_cols(*matrix)), 1, fp);
  for (int i = 0; i < get_rows(*matrix); i++) {
    fwrite(matrix->data[i], sizeof(int), get_cols(*matrix), fp);
  }
}

Matrix *read_matrix(FILE *fp) {
  Matrix *matrix = malloc(sizeof(Matrix));
  fread(&matrix->rows, sizeof(get_rows(*matrix)), 1, fp);
  fread(&matrix->cols, sizeof(get_cols(*matrix)), 1, fp);
  matrix->data = malloc(sizeof(int *) * get_rows(*matrix));
  for (int i = 0; i < get_rows(*matrix); i++) {
    matrix->data[i] = malloc(sizeof(int) * get_cols(*matrix));
    fread(matrix->data[i], sizeof(int), get_cols(*matrix), fp);
  }
  return matrix;
}

void print_matrix(Matrix *matrix) {
  for (int i = 0; i < get_rows(*matrix); i++) {
    for (int j = 0; j < get_cols(*matrix); j++) {
      printf("%2d ", get_value(*matrix, i, j));
    }
    printf("\n");
  }
}

Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2) {
  if (get_rows(*matrix1) != get_rows(*matrix2) ||
      get_cols(*matrix1) != get_cols(*matrix2)) {
    // Matrices have different dimensions, cannot be added
    printf("error: matrices have different dimensions, cannot be added\n");
    exit(EXIT_FAILURE);
  }

  Matrix *result = create_matrix(get_rows(*matrix1), get_cols(*matrix1));

  for (int i = 0; i < get_rows(*matrix1); i++) {
    for (int j = 0; j < get_cols(*matrix1); j++) {
      set_value(result, get_value(*matrix1, i, j) + get_value(*matrix2, i, j),
                i, j);
    }
  }

  return result;
}

int min_diff_col(Matrix *matrix) {
  int min_col = -1;
  int min_diff = INT_MAX;

  for (int j = 0; j < get_cols(*matrix); j++) {
    int max_diff = 0;

    for (int i = 1; i < get_rows(*matrix); i++) {
      int diff = abs(get_value(*matrix, i, j) - get_value(*matrix, i - 1, j));
      if (diff > max_diff) {
        max_diff = diff;
      }
    }

    if (max_diff < min_diff) {
      min_diff = max_diff;
      min_col = j;
    }
  }

  return min_col;
}

void print_matrix_col(Matrix *matrix, int col) {
  if (col < 0 || col >= get_cols(*matrix)) {
    printf("Invalid column index\n");
    return;
  }

  for (int i = 0; i < get_rows(*matrix); i++) {
    printf("%d\n", get_value(*matrix, i, col));
  }
}

Matrix *fill_matrix(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  set_rows(matrix, rows);
  set_cols(matrix, cols);
  matrix->data = malloc(sizeof(int *) * get_rows(*matrix));
  for (int i = 0; i < get_rows(*matrix); i++) {
    matrix->data[i] = malloc(sizeof(int) * get_cols(*matrix));
    for (int j = 0; j < get_cols(*matrix); j++) {
      set_value(matrix, rand() % 10, i, j);
    }
  }
  return matrix;
}

int main() {
  srand(time(NULL));

  int rows = rand() % MAX_ROWS + 2;
  int cols = rand() % MAX_ROWS + 2;

  // Generate two random matrices
  Matrix *matrix1 = fill_matrix(rows, cols);
  Matrix *matrix2 = fill_matrix(rows, cols);

  // Write the matrices to a file
  FILE *fp = fopen("matrices.bin", "wb");
  write_matrix(fp, matrix1);
  write_matrix(fp, matrix2);
  fclose(fp);

  // Read the matrices from the file and print them
  fp = fopen("matrices.bin", "rb");
  Matrix *read_matrix1 = read_matrix(fp);
  Matrix *read_matrix2 = read_matrix(fp);
  fclose(fp);

  printf("Matrix 1:\n");
  print_matrix(read_matrix1);
  printf("\nMatrix 2:\n");
  print_matrix(read_matrix2);

  Matrix *sum = add_matrices(matrix1, matrix2);
  printf("\nSomma:\n");
  print_matrix(sum);

  int min_col = min_diff_col(sum);
  printf("\nLa colonna con la differenza minore è:\n");
  print_matrix_col(sum, min_col);

  // Free memory
  destroy_matrices(matrix1, matrix2, read_matrix1, read_matrix2, sum);
  return 0;
}
