//
// Created by Luca Codorean on 11/21/2022.
//

#include <stdio.h>
#include <stdlib.h>

float* init_arr(int*);
void afisare(const float*, int);
void interclasare(float*, float*, float*, int, int);

const float max(float, float);

int main(void) {
    int size_of_first, size_of_second;

    float* first_arr = init_arr(&size_of_first);
    float* second_arr= init_arr(&size_of_second);

    int size_of_result = size_of_first + size_of_second;
    float* result_arr= (float*)calloc(size_of_result, sizeof(float));

    interclasare(first_arr, second_arr, result_arr, size_of_first, size_of_second);
    afisare(result_arr, size_of_result);

    free(first_arr), free(second_arr), free(result_arr);
    first_arr = NULL, second_arr = NULL, result_arr = NULL;
    return 0;
}

const float max(float a, float b) { return (a<b ? a : b); }

float* init_arr(int* size) {

    do {
        puts("Introduceti o marime pentru array.");
        scanf("%d", size);
    } while(*size<0);

    float* arr = (float*)calloc(*size, sizeof(float));
    for(int i = 0; i<*size; i++) scanf("%f", arr+i);

    return arr;
}

void afisare(const float* arr, int size) {
    for(int i = 0; i<size; i++) printf("%0.2f ", *(arr+i));
}

void interclasare(float* first_arr, float* second_arr, float* result_arr, int size_of_first, int size_of_second) {
    int index_first = 0, index_second = 0, index_result = 0;

    const float LIMIT = max(second_arr[size_of_second-1],first_arr[size_of_first-1])+1.0f;

    first_arr[size_of_first] = second_arr[size_of_second] = LIMIT;

    if(size_of_first<size_of_second) {
        int aux = size_of_first;
        while(aux<size_of_second) first_arr[aux++] = LIMIT;
    } else if(size_of_second<size_of_first) {
        int aux = size_of_second;
        while(aux<size_of_first) first_arr[aux ++] = LIMIT;
    }

    while(index_result <= size_of_second + size_of_first) {
        *(result_arr+(index_result++)) = (*(first_arr + index_first) < *(second_arr + index_second) ? *(first_arr + (index_first++)) :  *(second_arr + (index_second++)));
    }
}