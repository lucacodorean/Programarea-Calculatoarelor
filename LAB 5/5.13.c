#include <stdio.h>
#include <stdlib.h>

_Bool este_numar_perfect(int number);

int main(void) {
  puts("Introduceti o valoare competenta pentru n. n = ");
  int n; scanf("%d", &n);

  int l = 0, solution[n+1];
  for(int i = 0, number; i<n; i++) {
    scanf("%d", &number);
    if(este_numar_perfect(number)==true) {
      solution[l++] = number;
    }
  }

  puts("Numerele perfecte din sirul citit este:");
  for(int i = 0; i<l; i++) printf("%d\n", solution[i]);

  return 0;
}

_Bool este_numar_perfect(int number) {

    int sum = 0;

    if(number%2==0) {
      sum+=(2+(number/2));
    }

    for(int divisor = 3; divisor*divisor <= number; divisor+=2) {
      if(number%divisor==0) sum += (divisor + (number/divisor));
      if((number/divisor) == divisor) sum -= divisor;
    }

    return number == sum ? true : false;
}
