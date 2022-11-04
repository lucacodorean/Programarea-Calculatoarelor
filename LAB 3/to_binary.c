#include <stdio.h>

typedef char bool;

void convert(unsigned int number) {

    bool binary_version[32] = {0};
    int p = 0; unsigned int auxiliary = number;
    while (number>0) {
        binary_version[p++] = (bool)(number%2);
        number/=2;
    }

    for(int i = 31; i>=0; i--) {
        printf("%s%d", ((i+1)%8==0 ? " " : ""),binary_version[i]);
    } printf(" = %d\n", auxiliary);
}

int main() {
    unsigned int a, b;
    scanf("%d %d", &a, &b);
    convert(a); convert(b);
    convert(a & b);
    convert(a | b);
    convert(a << 3);
    convert(b >> 3);
    convert(a ^ b);
    return 0;
}