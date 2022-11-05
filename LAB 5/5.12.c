#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

_Bool este_patrat_perfect(int number);

int main(void) {
  puts("Introduceti o valoare competenta pentru n. n = ");
  int n; scanf("%d", &n);

  int l = 0, solution[n+1];
  for(int i = 0, number; i<n; i++) {
    scanf("%d", &number);
    if(este_patrat_perfect(number)==true) {
      solution[l++] = number;
    }
  }

  puts("Numerele patrat perfect din sirul citit este:");
  for(int i = 0; i<l; i++) printf("%d\n", solution[i]);

  return 0;
}

_Bool este_patrat_perfect(int number) {
    double radical = sqrt((double)number);
    return ((int)radical * (int)radical == number ? true : false);
}
