#include <stdio.h>
float equation(float x) { return (x * x - 3 * x + 5); }
float trapezoid(float h, float x0, float xn, float n) {
  float sum = 0, i;
  for (i = 1; i < n; i++) {
    sum += equation(x0 + i * h);
  }
  return (h / 2) * (equation(x0) + equation(xn) + 2 * sum);
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
  printf("The value of the integral is: %f\n", trapezoid(h, x0, xn, n));
}