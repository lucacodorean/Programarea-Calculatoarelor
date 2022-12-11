//
// Created by Luca Codorean on 11/28/2022.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int** init(int);
int HermiteR(int, int);
int Hermite(int, int);

int main(void) {
    printf("%d - recursiv \n%d - iterativ", HermiteR(5,2), Hermite(5,2));
    return 0;
}

int** init(int size) {
    int** matrix = (int**)calloc(size, sizeof(int*));

    for(int i = 0; i< MAX_N; i++) {
        matrix[i] = (int*)calloc(1, sizeof(int));
    }

    return matrix;
}

int Hermite(int ordin, int parameter) {

    if(ordin == 1) return parameter*2;
    if(ordin == 0) return 1;

    int** matrix = init(MAX_N);

    matrix[0][0] = 1;
    matrix[1][0] = 2*parameter;
    for(int actual_ordin = 2; actual_ordin<MAX_N; actual_ordin++) {
        matrix[actual_ordin][0] = 2*actual_ordin*matrix[actual_ordin-1][0] - 2*(actual_ordin-1)*matrix[actual_ordin-2][0];
    }

    int result = matrix[ordin][0];
    free(matrix), matrix = NULL;
    return result;
}

int HermiteR(int ordin, int parameter) {
    if(ordin==0) return 1;
    else {
        if(ordin==1) return parameter*2;
        if(ordin>1) return 2*ordin*HermiteR(ordin-1,parameter) - 2*(ordin-1)*HermiteR(ordin-2, parameter);
    }
}