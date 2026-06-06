#include <math.h>
#include <stdio.h>

float f(float x) {
  return 2 * pow(x, 5) + 3 * pow(x, 4) - 28 * pow(x, 3) - 15 * pow(x, 2) +
         62 * x - 24;
}
float df(float x) {
  return 10 * pow(x, 4) + 12 * pow(x, 3) - 84 * pow(x, 2) - 30 * x + 62;
}
float root() {
  int n = 0;
  float a;
  printf("Enter initial guess:");
  scanf("%f", &a);
  while (f(a) < -0.0001 || f(a) > 0.0001) {
    n++;
    printf("%dth iteration: %f\n", n, a);
    a = a - f(a) / df(a);
  }
  return a;
}
int main() {
  float r;
  r = root();
  printf("root is : %f", r);
  return 0;
}