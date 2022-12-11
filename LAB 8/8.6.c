#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void write(int);
void backtr(int);
_Bool complete(int);
int size, of, sol[MAX_SIZE] = {0}; int* arr;

int main(void) {

    scanf("%d %d", &size, &of);
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

_Bool complete(int k) { return of == k; }

void backtr(int k) {
    for(int i = sol[k-1]+1; i<=size; i++) {
        sol[k] = i;
        if(complete(k)==true) write(of);
        else backtr(k+1);
    }
}
