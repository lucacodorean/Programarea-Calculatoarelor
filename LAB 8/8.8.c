//
// Created by Luca Codorean on 11/28/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void write(int);
void backtr(int);
_Bool correct(int);
_Bool complete(int);
int size, sol[MAX_SIZE] = {0}; int* arr;

int main(void) {

    scanf("%d", &size);
    arr = (int*)calloc(size, sizeof(int));

    for(int i = 1; i<=size; i++) scanf("%d", arr+i);

    backtr(1);

    free(arr), arr=NULL;
    return 0;
}

void write(int limit) {
    for(int i = 1; i<=limit; i++) printf("%d ", sol[*arr+i]);
    printf("\n");
}

_Bool correct(int k) {
    for(int i = 1; i<=k-1; i++) {
        if(sol[i]==sol[k]) return false;
    }
    return true;
}

_Bool complete( int k) { return size == k; }

void backtr(int k) {
    for(int i = 1; i<=size; i++) {
        sol[k] = i;
        if(correct(k)==true) {
            if(complete(k)==true) write(k);
            else backtr(k+1);
        }
    }
}
