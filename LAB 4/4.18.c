#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n; scanf("%d", &n);

    int array[n][n];

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    _Bool ok = true;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
           if(array[i][j]!=array[j][i]) {
               ok = false;
               break;
           }
        } if(ok == false) break;
    }

    printf("Matricea%s este simetrica.", ok == true ?  "" : " nu");
    return 0;
}