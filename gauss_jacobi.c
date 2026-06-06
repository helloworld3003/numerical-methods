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
int is_diagonally_dominant(int m, int n, float arr[m][n]) {
  int i = 0, j = 0;
  float sum = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n - 1; j++) {
      if (i != j) {
        sum += arr[i][j];
      }
    }
    if (sum > arr[i][i]) {
      printf("The matrix is not diagonally dominant\n");
      return 0;
    }
    sum = 0;
  }
  printf("The matrix is diagonally dominant\n");
  return 1;
}
void gauss_jacobi(int m, int n, float arr[m][n]) {
  int i = 0, j = 0, k = 0;
  float x[m], error[m], temp[m], error2;
  for (i = 0; i < m; i++) {
    printf("Enter the first guess of x[%d]", i);
    scanf("%f", &x[i]);
  }
  float sum = 0;
  do {
    k++;
    printf("%dth iteration:\t", k);
    for (i = 0; i < m; i++) {

      sum = 0;
      for (j = 0; j < n; j++) {
        if (i != j) {
          sum += arr[i][j] * x[j];
        }
      }
      temp[i] = (arr[i][n - 1] - sum) / arr[i][i];
      error[i] = x[i] - temp[i];
      printf("%f\t", x[i]);
    }
    for (i = 0; i < m; i++) {
      error2 += error[i];
    }
    error2 = error2 / (m * 1.0);
    printf("%f\n", error2);
    for (i = 0; i < m; i++) {
      x[i] = temp[i];
    }
  } while (error2 < -0.0001 || error2 > 0.0001);
}
int main() {
  int m = 0, n = 0;
  printf("Enter number of rows");
  scanf("%d", &m);
  printf("Enter number of columns");
  scanf("%d", &n);
  float arr[m][n];
  arr_input(n, m, arr);
  if (is_diagonally_dominant(m, n, arr)) {
    gauss_jacobi(m, n, arr);
  }
  return 0;
}
