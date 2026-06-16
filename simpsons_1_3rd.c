#include <stdio.h>
float equation(float x) { return (x * x - 3 * x + 5); }
float simpsons_1_3rd(float h, float x0, float xn, float n) {
  float sum = 0, sum1 = 0, i;
  for (i = 1; i < n; i += 2) {
    sum += equation(x0 + i * h);
  }
  for (i = 2; i < n; i += 2) {
    sum1 += equation(x0 + i * h);
  }
  return (h / 3) * (equation(x0) + equation(xn) + 4 * sum + 2 * sum1);
}
int main() {
  float n, x0, xn, h; 
  printf("Enter the number of sub-intervals: ");
  scanf("%f", &n);
  printf("Enter the lower limit of integration: ");
  scanf("%f", &x0);
  printf("Enter the upper limit of integration: ");
  scanf("%f", &xn);
  h = (xn - x0) / n;
  printf("The value of the integral is: %f\n", simpsons_1_3rd(h, x0, xn, n));
}