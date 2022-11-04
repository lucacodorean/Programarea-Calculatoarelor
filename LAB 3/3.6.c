//
// Created by codor on 10/17/2022.
//

#include <stdio.h>

int main () {
    double x;
    scanf("%lf", &x);
    printf("%lf", x < -2 ? x*x-4*x+4 : (x==-2 ? 0 : x*x+5*x));
    return 0;
}