#include <stdio.h>

float f(float x) { return x * x * x - 5 * x + 1; }
float root(float a, float b) {
  float c;
  c = (a + b) / 2.0;
  printf("a=%f,b=%f,c=%f,f(c)=%f\n", a, b, c, f(c));
  while (f(c) < -0.0001 || f(c) > 0.0001) {
    printf("a=%f,b=%f,c=%f,f(c)=%f\n", a, b, c, f(c));
    c = (a + b) / 2.0;
    if (f(c) * f(a) < 0)
      b = c;
    else
      a = c;
  }
  return c;
}
int main() {
  float a, b, r;
  printf("lower limit of fxn:");
  scanf("%f", &a);
  printf("upper limit of fxn:");
  scanf("%f", &b);
  if (f(b) * f(a) > 0) {
    printf("wrong range");
    return 0;
  }
  r = root(a, b);
  printf("root is : %f", r);
  return 0;
}