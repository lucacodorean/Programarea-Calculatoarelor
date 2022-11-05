#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Este mai eficient daca lucrez cu array-uri de [size*size] in loc de matrice[size][size] ?

test:
  1 4 15
  4 3 30
  0 5 21
  1 2 14

  2 2 3
  1 4 2
  2 3 7
  5 3 0
  2 1 3*/

#define MAX 100
#define min(a,b) a<b ? a : b

struct Tupple {
  int i, j, value;
};

void init_tupple(struct Tupple arr[], int size);
void print_matrix(struct Tupple arr[], int size, int ordin);
void print_tupple(struct Tupple arr[], int size, char* string);
void sum(struct Tupple arr_A[], struct Tupple arr_B[], struct Tupple arr_result[], const int size_of_A, const int size_of_B, const int ordin);
void dif(struct Tupple arr_A[], struct Tupple arr_B[], struct Tupple arr_result[], const int size_of_A, const int size_of_B, const int ordin);
void inmultire(struct Tupple arr_A[], struct Tupple arr_B[], struct Tupple arr_result[], const int size_of_A, const int size_of_B, const int ordin);

int main(void) {
  puts("Introduceti numarul de elemente din fiecare matrice, respectiv ordinul matricelor.");
  printf("\n(matricea A) n= :"); int n; scanf("%d", &n);
  printf("\n(matricea B) m= :"); int m; scanf("%d", &m);
  printf("\n(ordin) o= :"); int o; scanf("%d", &o);

  struct Tupple A[n+1]; init_tupple(A,n); fflush(stdin);

  struct Tupple B[m+1]; init_tupple(B,m); fflush(stdin);
  struct Tupple resultS[n+m+1]; sum(A,B,resultS, n, m, o); fflush(stdout);
  struct Tupple resultD[n+m+1]; dif(A,B,resultD, n, m, o); fflush(stdout);
  struct Tupple result[n+m+1]; inmultire(A,B,result, n, m, o); fflush(stdout);

  return 0;
}
void print_tupple(struct Tupple arr_result[], int size, char* string) {
  printf("\n%s\nx y value\n", string);
  for(int i = 0; i<size; i++) {
    printf("%d %d %d\n", arr_result[i].i, arr_result[i].j, arr_result[i].value);
  }
}
void init_tupple(struct Tupple arr[], int size) {
  for(int i = 0; i<size; i++) {
      int x, y, value;
      scanf("%d %d %d", &x, &y, &value);
      arr[i].i = x;
      arr[i].j = y;
      arr[i].value = value;
  }
}
void print_matrix(struct Tupple arr[], int size, int ordin) {
   int matrix[ordin][ordin];

   for(int i = 0; i<ordin; i++) {
     for(int j = 0; j<ordin; j++) matrix[i][j] = 0;
   }

   for(int i = 0; i<size; i++) matrix[arr[i].i][arr[i].j] = arr[i].value;

   for(int i = 0; i<ordin; i++) {
     for(int j = 0; j<ordin; j++) {
       printf("%d ", matrix[i][j]);
     } printf("\n");
   }
}
void sum(struct Tupple arr_A[], struct Tupple arr_B[], struct Tupple arr_result[], const int size_of_A, const int size_of_B, const int ordin) {
  int *matrixA = (int *)malloc(ordin * ordin * sizeof(int));
  int *matrixB = (int *)malloc(ordin * ordin * sizeof(int));
  int *result  = (int *)malloc(ordin * ordin * sizeof(int));
  int l = 0;

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) *(matrixA + i*ordin + j)  = *(matrixB + i*ordin + j) = *(result + i*ordin + j) = 0;
  }

  for(int i = 0; i<size_of_A; i++) *(matrixA + arr_A[i].i*ordin + arr_A[i].j) = arr_A[i].value;
  for(int i = 0; i<size_of_B; i++) *(matrixB + arr_B[i].i*ordin + arr_B[i].j) = arr_B[i].value;

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) {
        *(result + i*ordin + j) = *(matrixA + i*ordin + j) + *(matrixB + i*ordin + j);
    }
  }

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) {
      if(*(result + i*ordin + j)!=0) {
        arr_result[l].i = i;
        arr_result[l].j = j;
        arr_result[l++].value = *(result + i*ordin + j);
      }
    }
  }

  free(matrixA);
  free(matrixB);
  free(result);

  print_tupple(arr_result, l, "Lista indicilor pentru suma.");
}
void dif(struct Tupple arr_A[], struct Tupple arr_B[], struct Tupple arr_result[], const int size_of_A, const int size_of_B, const int ordin) {
  int *matrixA = (int *)malloc(ordin * ordin * sizeof(int));
  int *matrixB = (int *)malloc(ordin * ordin * sizeof(int));
  int *result  = (int *)malloc(ordin * ordin * sizeof(int));
  int l = 0;

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) *(matrixA + i*ordin + j)  = *(matrixB + i*ordin + j) = *(result + i*ordin + j) = 0;
  }

  for(int i = 0; i<size_of_A; i++) *(matrixA + arr_A[i].i*ordin + arr_A[i].j) = arr_A[i].value;
  for(int i = 0; i<size_of_B; i++) *(matrixB + arr_B[i].i*ordin + arr_B[i].j) = arr_B[i].value;

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) {
        *(result + i*ordin + j) = *(matrixA + i*ordin + j) - *(matrixB + i*ordin + j);
    }
  }

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) {
      if(*(result + i*ordin + j)!=0) {
        arr_result[l].i = i;
        arr_result[l].j = j;
        arr_result[l++].value = *(result + i*ordin + j);
      }
    }
  }

  free(matrixA);
  free(matrixB);
  free(result);
  print_tupple(arr_result, l, "Lista indicilor pentru diferenta.");
}
void inmultire(struct Tupple arr_A[], struct Tupple arr_B[], struct Tupple arr_result[], const int size_of_A, const int size_of_B, const int ordin) {

  int *matrixA = (int *)malloc(ordin * ordin * sizeof(int));
  int *matrixB = (int *)malloc(ordin * ordin * sizeof(int));
  int *result  = (int *)malloc(ordin * ordin * sizeof(int));
  int l = 0;

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) *(matrixA + i*ordin + j)  = *(matrixB + i*ordin + j) = *(result + i*ordin + j) = 0;
  }

  for(int i = 0; i<size_of_A; i++) *(matrixA + arr_A[i].i*ordin + arr_A[i].j) = arr_A[i].value;
  for(int i = 0; i<size_of_B; i++) *(matrixB + arr_B[i].i*ordin + arr_B[i].j) = arr_B[i].value;

  for(int i = 0; i<ordin; i++) {
    for(int k = 0; k<ordin; k++) {
      for(int j = 0; j<ordin; j++) {
          *(result + i*ordin + k) += *(matrixA + i*ordin + j) * *(matrixB + j*ordin + k);
      }
    }
  }

  for(int i = 0; i<ordin; i++) {
    for(int j = 0; j<ordin; j++) {
      if(*(result + i*ordin + j)!=0) {
        arr_result[l].i = i;
        arr_result[l].j = j;
        arr_result[l++].value = *(result + i*ordin + j);
      }
    }
  }

  free(matrixA);
  free(matrixB);
  free(result);

  print_tupple(arr_result, l, "Lista indicilor pentru inmultire.");
}
