#include <stdio.h>

void solve(int number) {
    int p = 1, d = 2;
    if(number == 0) {
        printf("Error: Given number is 0.");
        return;
    } else {
        while(number>1) {
            p = 0;
            while(number%d==0) {
                p++;
                number/=d;
            }
            if(p)
                (p!=1) ? printf("pow(%d,%d) ", d,p) : printf("%d", d);
            d++;
            if(d*d>number) d = number;
        }
    }
}

int main() {
    int number;
    printf("Insert a proper value for the number."); scanf("%d", &number);
    solve(number);
    return 0;
}