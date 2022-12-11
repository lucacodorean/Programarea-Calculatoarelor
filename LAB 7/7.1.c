//
// Created by Luca Codorean on 11/10/2022.
//


#include <stdio.h>
#include <stdlib.h>

void citire(int**, int);
void afisare(int**, int);
void inmultire(int**, int**, int, int**, int*);

int main(void) {
    int size, result_size = 0;

    puts("Introduceti marimea matricei patratice.");
    scanf("%d", &size);
    int** matrixA =  (int**)calloc((size), sizeof(int*));
    int** matrixB =  (int**)calloc((size), sizeof(int*));
    int**  result =   (int**)calloc((size), sizeof(int*));

    for(int i = 0; i<size; i++) {
        *(matrixA+i) = (int*)calloc((size), sizeof(int));
        *(matrixB+i) = (int*)calloc((size), sizeof(int));
        *(result+i)  = (int*)calloc((size), sizeof(int));
    }

    citire(matrixA, size);
    citire(matrixB, size);

    inmultire(matrixA, matrixB, size, result, &result_size);
    puts("AB = ");
    afisare(result, result_size);

    free(matrixA);     matrixA = NULL;
    free(matrixB);     matrixB = NULL;
    free(result);      result  = NULL;

    return 0;
}

void citire(int** matrix, int size) {
    for(int i = 0; i<size; i++) {
        for(int j = 0; j<size; j++) scanf("%d", (*(matrix+i)+j));
    }
}

void afisare(int** matrix, int size) {
    for(int i = 0; i<size; i++) {
        for(int j = 0; j<size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        } printf("\n");
    }
}

void inmultire(int** first, int** second, int size, int** result, int* size_result) {
    for(int i = 0; i<size; i++) {
        for(int j = 0; j<size; j++) {
            for(int k = 0; k<size; k++) {
                *(*(result + i) + j) = (*(*(first + i) + k)) * (*(*(second + k) + j));
            }
        }
    }

    *size_result = size;
}