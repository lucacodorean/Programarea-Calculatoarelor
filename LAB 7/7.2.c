//
// Created by Luca Codorean on 11/11/2022.
//

#include <stdio.h>
#include <stdlib.h>


void sort(int*, int);
void swap(int*, int*);

int main(void) {
    int* array = 0;
    int  size; scanf("%d", &size);
    array = (int*) calloc(size, sizeof(int));

    for(int i = 0; i<size; i++) scanf("%d", array+i);

    sort(array,size);
    for(int i = 0; i<size; i++) printf("%d ", *(array+i));

    free(array);
    return 0;
}

void swap(int* first, int* second) {
    *first =    *first ^ *second;
    *second =   *first ^ *second;
    *first =    *second ^ *first;
}

void sort(int* array, int size) {
    for(int i = 0; i<size; i++) {
        for(int j = i; j<size-1; j++) {
            if(*(array+i) < *(array+j)) swap((array+i), (array+j));
        }
    }
}