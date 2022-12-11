#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * p(x) = a0 + a1*x + a2*x^2 + a3 * x^3 => size = 4
 * .... =  0    1     2         3
 *
 *
 *         0    1     2         3
 * p'(x) = 0 + a1 + 2*a2*x + 3*a3*x^3.
 *
 *
 *         0     1     2      3
 * p(x)      = 1 + 2*x + 3*x^2 + 4*x^3
 * p'(x)    = 0 + 2   + 2*3*x + 3*4*x^2
 * p'(2)    = 0 + 2   + 2*3*2 + 3*4*4
 *          = 62
*/

void init(double*, const int*, double*);
double derivative(const double*, int, double);

int main(void) {
    int degree = 0;
    double value = 0;

    puts("Introduceti gradul polinomului: "); scanf("%d", &degree);
    double* polynome = (double*) calloc(degree, sizeof(double));
    init(polynome, &degree, &value);
    printf("In ce punct calculati derivata? x = "); scanf("%lf", &value);

    double result = derivative(polynome, degree, value);
    printf("Valoarea P'(%lf) = %0.3lf", value, result);

    free(polynome); polynome = NULL;
    return 0;
}

void init(double* arr, const int* size, double* value) {

    puts("Introduceti valori coeficientii polinomului");
    for(int i = 0; i<*size; i++) {
        scanf("%lf", arr+i);
    }

}

double derivative(const double* arr, int size, double x) {
     double result = 0;
     for(int i = 1; i<size; i++) {
        result += *(arr+i) * i * pow(x,i-1);
    }
     return result;
}
