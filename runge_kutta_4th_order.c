#include <stdio.h>
double equation(double x, double y) { return (y); }
double runge_kutta(double h,double n) {
  double i, x = 0, y = 1;
  double k1,k2,k3,k4;
  for(i=0;i<n;i++){
    k1=h*equation(x,y);
    k2=h*equation(x+0.5*h,y+0.5*k1);
    k3=h*equation(x+0.5*h,y+0.5*k2);
    k4=h*equation(x+h,y+k3);
    y = y + (k1+2*k2+2*k3+k4)/6;
    x = x + h;
  }
  return y; 
}
int main() {
  double n, h,x;
  printf("Enter the number of sub-intervals: ");
  scanf("%lf", &n);
  printf("Enter value of x for which you want to find the value: ");
  scanf("%lf", &x);
  h = x / n;
  printf("Solution of the differential equation is: %lf\n", runge_kutta(h,n));
  return 0;
}