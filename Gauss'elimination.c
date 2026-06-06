#include <stdio.h>
void arr_input(int n, int m, float arr[m][n]) {
  int i = 0, j = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter %d,%d element", i, j);
      scanf("%f", &arr[i][j]);
    }
  }
}
void arr_copy(int n, int m, float arr[m][n], float arr2[m][n]) {
  int i = 0, j = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      arr2[i][j] = arr[i][j];
    }
  }
}
void row_multiply(int m, int n, float arr2[m][n], int row, float multiplier) {
  int j = 0;
  for (j = 0; j < n; j++) {
    arr2[row][j] = arr2[row][j] * multiplier;
  }
}
void row_subtract(int m, int n, float arr[m][n], int row1, int row2,
                  float arr2[m][n]) {
  int j = 0;
  for (j = 0; j < n; j++) {
    if (j != row2) {
      arr[row1][j] = arr2[row1][j] - arr2[row2][j];
    } else {
      arr[row1][j] = 0;
    }
  }
}
void print_arr(int m, int n, float arr[m][n]) {
  int i = 0, j = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%f\t", arr[i][j]);
    }
    printf("\n");
  }
}
void gauss_elimination(int m, int n, float arr[m][n], float arr2[m][n]) {
  int i = 0, j = 0, k = 0;
  float x[m];
  printf("Gauss' elimination:\n");
  for (i = 0; i < m - 1; i++) {
    for (j = i + 1; j < n; j++) {
      float multiplier = arr[j][i] / arr[i][i];
      row_multiply(m, n, arr2, i, multiplier);
      row_subtract(m, n, arr, j, i, arr2);
      arr_copy(n, m, arr, arr2);
    }

    k++;
    printf("%dth iteration:\n", k);
    print_arr(m, n, arr);
  }
  for (j = m - 1, i = m - 1; j >= 0; j--, i--) {
    x[i] = arr[j][n - 1];
    for (k = n - 2; k > j; k--) {
      x[i] -= x[k] * arr[j][k];
    }
    x[i] = x[i] / arr[j][j];
  }
  printf("\n\nanswer:\n");
  for (i = 0; i < m; i++) {
    printf("%f\t", x[i]);
  }
}
int main() {
  int m = 0, n = 0;
  printf("Enter number of rows");
  scanf("%d", &m);
  printf("Enter number of columns");
  scanf("%d", &n);
  float arr[m][n];
  float arr2[m][n];
  arr_input(n, m, arr);
  arr_copy(n, m, arr, arr2);
  print_arr(m, n, arr2);
  gauss_elimination(m, n, arr, arr2);
  return 0;
}