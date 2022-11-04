#include <stdio.h>

int factorial_rec(int limit);
int factorial(int limit);

int main() {
    int n; scanf("%d", &n);
    if(n>100) printf("Eroare");
    else {
        int p = factorial(n);
        printf("%d", p);
    }
    return 0;
}

int factorial_rec(int limit) {
    if(limit == 1) return 1;
    else return limit*factorial_rec(limit-1);
}

int factorial(int limit) {
    int p = 1;
    for(int number=2; number<=limit; number++) {
        p*=number;
    }
    return p;
}
