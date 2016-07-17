/*
 * TODO Implement O(n) subarray solution 4.1-5
 */

#include <stdlib.h>
#include <stdio.h>

#define ialloc(var) malloc(var * sizeof(int));
#define NEG_INT -2147483648

struct subarray {
  int left;
  int right;
  int sum;
};

struct subarray fmcsa (int *array, int low, int mid, int high);
struct subarray fmsa (int *array, int low, int high);

int main (int argc, char **argv)
{
  int test[8] = { 60, 30, -6, 8, 15, 18, -8, 4 };
  struct subarray result;
  result = fmsa(test, 0, 7);
  printf("L: %i\n", result.left);
  printf("R: %i\n", result.right);
  printf("S: %i\n", result.sum);
}

/*
 * Find Max Crossing Sub Array
 * must allocate space for 3 integers after this function returns
 */
struct subarray
fmcsa (int *array, int low, int mid, int high)
{
  int left_sum, right_sum, sum, i, max_left, max_right;
  struct subarray tuple;
  
  i = max_left = max_right = 0;
  sum = 0;
  left_sum = -2147483648;
  for (i = mid; i > low; i--) {
    sum = sum + array[i];
    if (sum > left_sum) {
      left_sum = sum;
      max_left = i;
    }
  }
  
  sum = 0;
  right_sum = -214783648;
  for (i = mid + 1; i < high; i++) {
    sum = sum + array[i];
    if (sum > right_sum) {
      right_sum = sum;
      max_right = i;
    }
  }
  
  tuple.left = max_left;
  tuple.right = max_right;
  tuple.sum = (left_sum != NEG_INT && right_sum != NEG_INT) ? left_sum + right_sum : 0;
  return tuple;
}

/*
 *
 */
struct subarray
fmsa (int *array, int low, int high)
{
  int mid;
  struct subarray tuple, left, right, cross;

  if (high == low) {
    tuple.left = low;
    tuple.right = high;
    tuple.sum = array[low];
    return tuple;
  }
  
  mid = ((low + high)/2);
  
  left = fmsa(array, low, mid);
  right = fmsa(array, mid + 1, high);
  cross = fmcsa(array, low, mid, high);
  
  if (left.sum >= right.sum && left.sum >= cross.sum) {
    return left;
  } else if (right.sum >= left.sum && right.sum >= cross.sum) {
    return right;
  } else {
    return cross;
  }
}

