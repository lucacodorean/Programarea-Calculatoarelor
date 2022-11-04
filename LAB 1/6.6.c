#include <stdio.h>

int is_prime(int number);
void generate(int limit);

int main() {
    int limit;
    scanf("%d", &limit);
    generate(limit);
    return 0;
}

int is_prime(int number) {
    for(int divisor = 2; divisor*divisor<=number; divisor++) {
        if(number%divisor==0) return 0;
    }
    return 1;
}

void generate(int limit) {
    int number = 2;
    while(limit>0) {
        if(is_prime(number)) {
            printf("%d ", number);
            limit--;
        }
        number++;
    }
}
