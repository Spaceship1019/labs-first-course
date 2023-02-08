#include <stdio.h> 
#include <math.h> 
long double MachineEpsilon() {
    long double e = 1.01;
    while (1 + e * 0.5 > 1) {
        e *= 0.51;
    }
    return e;
}

double f(double x) {
    return 3 * tan(x) * x - 1;
}

double fder(double x) {
    //return (cos(mid) * sin(mid) + mid) / (cos(mid) * cos(mid))
    return (3 * sin(2 * x) + 6 * x) /  (cos(x) * cos(x));
}

int main(){
  printf("%d\n", 1);
  double a = 0.2, b = 1.0;
  double xi = 0, mid = (a + b) / 2;
  long double eps = MachineEpsilon();
  while (1) {
      printf("%f\n", mid);
      xi = mid - f(mid) / fder(mid);
      if (fabs(xi - mid) < eps || fabs(xi - mid) > 1) break;
       
      printf("%f\n", xi);
      
      mid = xi;
      
  }
  printf("%f\n", xi);
}
