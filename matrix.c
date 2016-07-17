/*
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct matrix {
  int rows;
  int cols;
  int *vals;
} matrix;

void putsmat (struct matrix* mat);
struct matrix * nmat (int rows, int cols);
struct matrix * smatmult (struct matrix* A, struct matrix* B);
int ** sodaif (int *array, int n);

int main (int argc, char **argv)
{
  struct matrix* mat = nmat(2, 2);
  
  free(mat);
  mat = nmat(4, 4);
  mat->vals[10] = 5;
  putsmat(mat);
  printf("\n");
  struct matrix* mat2 = nmat(4, 4);
  for (int i = 0; i < 16; i++) {
    mat->vals[i] = 4;
    mat2->vals[i] = 3;
  }
  struct matrix* matmul = smatmult(mat, mat2);
  putsmat(matmul);

  int testvals[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  int **testdub;

  printf("\n");

  testdub = sodaif(testvals, 4);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf ("%i   ", testdub[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

/*
 * PutsMatrix
 * 
 * prints a matrix to the console
 */
void
putsmat (struct matrix* mat)
{
  int k = 0;
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->cols; j++) {
      printf("%i   ", mat->vals[k]);
      k++;
    }
    printf("\n");
  }
}

/*
 * NewMatrix
 * 
 * returns a pointer to a new matrix
 */
struct matrix*
nmat (int rows, int cols)
{
  if (rows <= 0 || cols <=0) {
    return NULL;
  }
  
  struct matrix *mat = malloc(sizeof(matrix));
  
  mat->rows = rows;
  mat->cols = cols;
  mat->vals = malloc(rows*cols*sizeof(int));
  
  for (int i = 0; i < rows * cols; i++) {
    mat->vals[i] = 0;
  }
  
  return mat;
}

/*
 * Square Matrix Multiplication (Slow Matrix Multiplication)
 *
 * smat mult
 */
struct matrix*
smatmult (struct matrix* A, struct matrix* B)
{
  if (A->rows != A->cols || B->rows != B->cols || A->rows != B->cols)
    return NULL;

  int i, j, k, l, n;
  i = j = k = l = 0;
  n = A->rows;
  
  struct matrix* C = nmat(A->rows, A->rows);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      C->vals[l] = 0;
      for (k = 0; k < n; k++) {
	C->vals[l] = C->vals[l] + A->vals[i + j] * B->vals[i + j];
      }
      l++;
    }
  }

  return C;
  
}

/*
 * Split one dimensional array into four
 * Splits an array representing the value of a matrix into its four quadrents
 * n is the square root of the length of the array
 */
int **
sodaif (int *array, int n)
{
  int **out_array, i, j, k, *arr1, *arr2, *arr3, *arr4;

  arr1 = malloc(sizeof(int));
  arr2 = malloc(sizeof(int));
  arr3 = malloc(sizeof(int));
  arr4 = malloc(sizeof(int));

  int l, m;
  l = m = 0;
  for (i = 0; i < n / 2; i++) {
    k = i * n;
    for (j = 0; j < n / 2; j++) {
      arr1[l] = array[k];
      k++; l++;
    }
    for (j = 0; j < n / 2; j++) {
      arr2[m] = array[k];
      k++; m++;
    }
  }

  l = m = 0;
  for (i = n / 2; i < n; i++) {
    k = i * n;
    for (j = 0; j < n / 2; j++) {
      arr3[l] = array[k];
      k++; l++;
    }
    for (j = 0; j < n / 2; j++) {
      arr4[m] = array[k];
      k++; m++;
    }
  }

  out_array = malloc(4 * sizeof(int*));

  out_array[0] = arr1;
  out_array[1] = arr2;
  out_array[2] = arr3;
  out_array[3] = arr4;

  return out_array;
  
}
