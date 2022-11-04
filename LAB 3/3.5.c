//
// Created by Luca Codorean on 10/18/2022.
//

#include <stdio.h>

int main() {
    int number; scanf("%d", &number);
    printf("Anul %s", (number % 366 ==0 ? "este bisect." : "nu este bisect."));
    return 0;
}