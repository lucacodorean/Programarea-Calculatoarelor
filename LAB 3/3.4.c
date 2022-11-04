//
// Created by Luca Codorean on 10/18/2022.
//

#include <math.h>
#include <stdio.h>

#define PI 3.141592

int main() {
    double constanta_multiplicare = PI/180.0;
    double number;
    scanf("%lf", &number);
    double grade = number*constanta_multiplicare;

    printf("Valoarea lui cos(%0.2lf) este %lf.\n", number, cos(grade));
    printf("Valoarea lui sin(%0.2lf) este %lf.\n", number, sin(grade));
    printf("Valoarea lui tan(%0.2lf) este %lf.\n", number, tan(grade));

    int a, b; char x;
    scanf("%c", &x);
    scanf("%d %d", &a,&b);

    return 0;
}
