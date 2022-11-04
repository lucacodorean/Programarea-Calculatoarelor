//
// Created by Luca Codorean on 10/24/2022.
//

#include <stdio.h>
#include <math.h>

void printPolinom(char function_name, char parameter, int coef[], int size) {
    printf("%c(%c) = ", function_name, parameter);
    int j = size;
    for(int i = 0; i<=size; i++) {
        printf(" %d%c^%d%s ", coef[i], parameter, j--, (i != size ? (coef[i] > 0 ? "+" : "-") : ""));
    }
}

long long evalPolinom(int coef[], int grad, int value) {
    int result = 0;
    for(int i = 0; i<grad; i++) {
        result += (coef[i]*pow(value,i));
    }
    return result;
}

int main () {


    int n,x;
    scanf("%d", &n);
    int coef[n+1];

    for(int i = 0; i<n+1; i++) {
        scanf("%d", &coef[i]);
    }

    printf("x= "); scanf("%d", &x);
    printPolinom('F', 'a', coef, n);
    printf("\n%c(%d) = %lld", 'F', x, evalPolinom(coef, n, x));
    return 0;
}