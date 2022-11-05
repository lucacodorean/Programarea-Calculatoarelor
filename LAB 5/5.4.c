#include <stdio.h>
#include <stdbool.h>

#define MAX 101

#define GREATER 1
#define EQUAL 0
#define LOWER -1

const int max(int first, int second);
const int min(int first, int second);

void citireNumar(int* arr, int* size);
void printareNumar(int* arr, int size, char symb, char sign);
int compare(int* first, int* second, int size_of_first, int size_of_second);
void adunaNumereMari(int* first, int* second, int size_of_first, int size_of_second, int* result, int* size_of_result);
void diferenta(int* first, int* second, int size_of_first, int size_of_second, int* result, int* size_of_result);
void scadeNumereMari(int* first, int* second, int size_of_first, int size_of_second, int* result, int* size_of_result);
void inmultireNumereMari(int* first, int* second, int size_of_first, int size_of_second, int* result, int *size_of_result);

int main(void) {
    int size_of_a=0, size_of_b=0, size_of_c=0, size_of_d = 0, size_of_i = 0;
    int A[MAX] = {0}, B[MAX] = {0}, C[MAX] = {0}, D[MAX] = {0}, I[MAX] = {0};

    citireNumar(A, &size_of_a);
    fflush(stdin);
    citireNumar(B, &size_of_b);

    printf("%d\n", compare(A,B,size_of_a, size_of_b));

    printareNumar(A, size_of_a, 'a', '+');
    printareNumar(B, size_of_b, 'b', '+');

    adunaNumereMari(A,B, size_of_a, size_of_b, C, &size_of_c);
    printareNumar(C, size_of_c, 'c', '+');

    scadeNumereMari(A,B, size_of_a, size_of_b, D, &size_of_d);
    printareNumar(D, size_of_d, 'd', size_of_a > size_of_b ? '+' : '-');

    inmultireNumereMari(A,B,size_of_a, size_of_b, I, &size_of_i);
    printareNumar(I, size_of_i, 'i', '+');

    return 0;
}

const int max(int first, int second) { return first > second ? first : second; }
const int min(int first, int second) { return first < second ? first : second; }

void citireNumar(int arr[], int* size) {
    puts("Introdu numarul de cifre pentru numarul mare: ");
    scanf("%d", size);
    fflush(stdin);                  /// -> goleste bufferul.

    for(int i = *size; i>=0; i--) {
        char c; scanf("%csize_of_first", &c);
        arr[i] = c - '0';
    }
}

void printareNumar(int* arr, int size, char symb, char sign) {
    printf("%c este: %s", symb, sign=='+' ? "" : "-");
    for(int i = size-1; i>=0; i--) {
        printf("%d", arr[i]);
    }
    fflush(stdout); printf("\n");
}

int compare(int* first, int* second, int size_of_first, int size_of_second) {
  if(size_of_first!=size_of_second) {
    if(size_of_first > size_of_second) return GREATER;
    if(size_of_second > size_of_first) return LOWER;
  } else {

      while(!first[size_of_first] && size_of_first>1) size_of_first--;
      while(!second[size_of_second] && size_of_second>1) size_of_second--;

      int ok = 0;

      for(int i = size_of_first; i>=0; i--) {
         if(first[i] < second[i]) {
            return LOWER;
         } else if(first[i] == second[i]) ok ++;
      }

      if(ok == size_of_first) return EQUAL;
  }

  return GREATER;
}

void adunaNumereMari(int* first, int* second, int size_of_first, int size_of_second, int* result, int* size_of_result) {

   *size_of_result = max(size_of_second, size_of_first);

   if(size_of_first>size_of_second) {
     for(int i = size_of_first; i>=size_of_second; i--) second[i] = 0;
   } else {
     for(int i = size_of_second; i>=size_of_first; i--) first[i] = 0;
   }


    int t = 0;
    for(int i = 0; i<*size_of_result; i++) {
        t = (first[i] + second[i]+t);
        result[i] = t%10;
        t/=10;
    }

    if(t>0) {
      result[++(*size_of_result)] = t%10;
      t/=10;
    }
}

void diferenta(int* first, int* second, int size_of_first, int size_of_second, int* result, int* size_of_result) {

    *size_of_result = size_of_first;

    int t = 0;

    for(int i = size_of_second; i<size_of_first; i++) second[i] = 0;

    for(int i = 0; i<*size_of_result; i++) {
      result[i] = first[i] - (second[i] + t);
      t = (result[i] < 0 ? 1 : 0);
      if(t!=0) result[i]+=10;
    }

    while(result[*size_of_result-1]==0 && *size_of_result>0) *size_of_result = *size_of_result - 1;
}

void scadeNumereMari(int* first, int* second, int size_of_first, int size_of_second, int* result, int* size_of_result) {
  int decider = compare(first, second, size_of_first, size_of_second);

  if(decider == GREATER) diferenta(first, second, size_of_first, size_of_second, result, size_of_result);
  else {
    diferenta(second, first, size_of_second, size_of_first, result, size_of_result);

  }
}

void inmultireNumereMari(int* first, int* second, int size_of_first, int size_of_second, int* result, int *size_of_result) {

  *size_of_result = size_of_first + size_of_second;

  int t = 0;
  
  for(int i = 0; i<size_of_first; i++) {
    for(int j = 0; j<size_of_second; j++) {
      result[i+j] = first[i] * second[j];
    }
  }

  for(int i = 0; i<*size_of_result; i++) {
    t = t + result[i];
    result[i] = t%10;
    t/=10;
  }

  if(t!=0) {
    result[++(*size_of_result)] = t;
  }

  while(result[*size_of_result-1]==0 && *size_of_result>0) *size_of_result = *size_of_result - 1;
}
