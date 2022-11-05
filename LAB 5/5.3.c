#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

_Bool reflexiva (int* x, int* y, int size);
_Bool tranzitiva(int* x, int* y, int size);
_Bool simetrica (int* x, int* y, int size);
_Bool exists(int elem, int* arr, int size_of_arr);
_Bool echivalenta(int* x, int* y, int size);

int main() {
  int n;

  printf("%s\n", "Introduceti numarul de perechi (x,y).");
  scanf("%d", &n);

  int x[MAX] = {0}, y[MAX] = {0};
  for(int i = 0; i<n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }

  printf("%s relatie de echivalenta de la x la y.\n", echivalenta(x,y,n) == true ? "Exista" : "Nu exista");


  return 0;
}

_Bool exists(int elem, int* arr, int size_of_arr) {
  for(int i = 0; i<size_of_arr; i++) {
    if(elem==arr[i]) return true;
  }

  return false;
}

_Bool reflexiva(int* x, int* y, int size) {

  _Bool ok = false;

  for(int i = 0; i<size && ok == false; i++) {
    if(y[i]==x[i]) {
      ok = true;
    }
  }

  return ok;
}

_Bool tranzitiva(int* x, int* y, int size) {
  for(int i = 0; i<size; i++) {
    if(exists(y[i], x, size)!=true) return false;
  }
  return true;
}

_Bool simetrica (int* x, int* y, int size) {
  int ok = 0;

  for(int i = 0; i<size; i++) {
    if(exists(y[i], x, size)==true) {
      ok++;
      break;
    }
  }

  for(int i = 0; i<size; i++) {
    if(exists(x[i], y, size)==true) {
      ok++;
      break;
    }
  }

  return (ok == 2 ? true : false);
}

_Bool echivalenta(int* x, int* y, int size) {
  return tranzitiva(x,y,size) == true && simetrica(x,y,size) == true && reflexiva(x,y,size) == true ? true : false;
}
