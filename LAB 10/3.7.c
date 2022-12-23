//
// Created by Luca Codorean on 12/18/2022.
//

#include <stdio.h>
#include <stdlib.h>

enum bool {false, true};
enum bool correct(int, int);
void swap(int*, int*);
void sort(int*, int, enum bool (*)(int, int));

int main(void) {
    int n; scanf("%d", &n);
    int* arr = (int*)calloc(n, sizeof(int));

    for(size_t i = 0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr,n, correct);

    for(size_t i = 0; i<n; i++) printf("%d ", arr[i]);

    free(arr);
    return 0;
}

enum bool correct(int a, int b) {
    return (a<b ? true : false);
}

void swap(int* first, int* second) {
    *first =    *first ^ *second;
    *second =   *first ^ *second;
    *first =    *second ^ *first;
}

void sort(int arr[], int size, enum bool(*comparition_function)(int, int)) {
    enum bool finished;
    do {
        finished = true;
        for (size_t i = 0; i < size; i++) {
            if (comparition_function(arr[i], arr[i - 1]) == true) {
                swap(&arr[i], &arr[i - 1]);
                finished = false;
            }
        }
    } while(!finished);
}