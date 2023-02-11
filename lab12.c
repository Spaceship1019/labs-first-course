#include <stdio.h>

//Compiler version gcc  6.3.0

int main() {
  int ind, pr, numb;
  scanf("%d", &numb);
  pr = numb % 10;
  numb /= 10;
  int c = 0;
  numb = fabs(numb);
  while (numb > 0) {
    ind = numb % 10;
    if (ind == pr) {
      printf("%s", "yes");
      return 0;
    }
    pr = ind;
    numb /= 10;
    
  }
  printf("%s", "No");
  return 0;
}