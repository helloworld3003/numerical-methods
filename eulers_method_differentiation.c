#include <stdio.h>
float equation(float x, float y) { return (-3*y); }
float euler(float h,float n) {
  float i, x = 0, y = 1;
  for(i=0;i<n;i++){
    y = y + h * equation(x,y);
    x = x + h;
  }
  return y; 
}
int main() {
  float n, h,x;
  printf("Enter the number of sub-intervals: ");
  scanf("%f", &n);
  printf("Enter value of x for which you want to find the value: ");
  scanf("%f", &x);
  h = x / n;
  printf("Solution of the differential equation is: %f\n", euler(h,n));
  return 0;
}