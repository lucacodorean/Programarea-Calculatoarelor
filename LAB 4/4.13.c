//
// Created by Luca Codorean on 10/30/2022.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n; scanf("%d", &n);
    int prevNumber;
    int* arr= malloc(n*sizeof(int));
    int* result = malloc(n*sizeof(int));

    scanf("%d", &prevNumber); n--;
    int size = 1, current_size = 1, max_size = 1;
    arr[0] = prevNumber;

    for(int i = 0, number; i<n; i++) {
        scanf("%d", &number);
        if(number > prevNumber) {
            current_size++;
            arr[size++] = number;
        } else {
            if(current_size>max_size) {
                max_size = current_size;
                for(int j = 0; j<max_size; j++) result[j] = arr[j];
            }

            for(int j = 0; j<size; j++) arr[j] = 0;
            size = 0;
            arr[size] = number;
            current_size = 1;
        }

        prevNumber = number;
    }

    for(int i = 0; i<max_size; i++) printf("%d ", result[i]);
    free(arr);
    free(result);
    return 0;
}