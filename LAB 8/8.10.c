#include <stdlib.h>
#include <stdio.h>

int Ackermann(int, int);

int main(void) {
    int m,n; scanf("%d %d", &m, &n);
    printf("%d", Ackermann(m,n));
    return 0;
}

int Ackermann(int m, int n) {
    if(n!=0 && m == 0) return n+1;
    else {
        if(m!=0 && n == 0) return Ackermann(m-1,1);
        else if(n!=0 && m!=0) return Ackermann(m-1, Ackermann(m,n-1));
    }
}