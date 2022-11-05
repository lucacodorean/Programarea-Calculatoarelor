#include <stdio.h>

#define MAX 50

void init_mat(int arr[MAX][MAX], int n);
void print_mat(int arr[MAX][MAX], int n);
void add(int matrix_a[MAX][MAX], int matrix_b[MAX][MAX], int result[MAX][MAX], int n);
void subtract(int matrix_a[MAX][MAX], int matrix_b[MAX][MAX], int result[MAX][MAX], int n);
void inmultire(int matrix_a[MAX][MAX], int matrix_b[MAX][MAX], int result[MAX][MAX], int n);


int main() {
  int n; scanf("%d", &n);

  int A[MAX][MAX] = {0};
  int B[MAX][MAX] = {0};
  int S[MAX][MAX] = {0};
  int S2[MAX][MAX] = {0};
  int D[MAX][MAX] = {0};
  int I[MAX][MAX] = {0};

  init_mat(A,n); printf("\n"); init_mat(B,n);

  inmultire(A,B,I,n);   // b*c
  add(A,B,S2,n);        // b+c
  add(S2,S2,S,n);       // 2*(b+c)
  subtract(I,S,D,n);    // b*c - 2*(b+c)

  print_mat(D,n);

  return 0;
}

void init_mat(int arr[MAX][MAX], int n) {
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}
void print_mat(int arr[MAX][MAX], int n) {
  printf("\n");
  for(int i =0; i<n; i++) {
    for(int j =0; j<n; j++) {
      printf("%d ", arr[i][j]);
    } printf("\n");
  }
}
void inmultire(int matrix_a[MAX][MAX], int matrix_b[MAX][MAX], int result[MAX][MAX], int n) {
  for(int i = 0; i<n; i++) {
    for(int k = 0; k<n; k++) {
      for(int j = 0; j<n; j++) {
          result[i][k] += matrix_a[i][j] * matrix_b[j][k];
      }
    }
  }
}
void add(int matrix_a[MAX][MAX], int matrix_b[MAX][MAX], int result[MAX][MAX], int n) {
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      result[i][j] = matrix_a[i][j] + matrix_b[i][j];
    }
  }
}
void subtract(int matrix_a[MAX][MAX], int matrix_b[MAX][MAX], int result[MAX][MAX], int n) {
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      result[i][j] = matrix_a[i][j] - matrix_b[i][j];
    }
  }
}
