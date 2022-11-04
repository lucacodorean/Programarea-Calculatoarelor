//
// Created by Luca Codorean on 10/21/2022.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    int stanga = 0; int dreapta = num-1;
    while(stanga<dreapta) {
        arr[stanga]     = arr[stanga] ^ arr[dreapta];
        arr[dreapta]    = arr[stanga] ^ arr[dreapta];
        arr[stanga]     = arr[dreapta] ^ arr[stanga];
        stanga++; dreapta--;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
