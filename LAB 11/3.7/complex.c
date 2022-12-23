#include "complex.h"
#include <math.h>

float set_module(COMPLEX* number) {
    return sqrt(pow(number->real, 2) + pow(number->imaginary, 2));
}

float set_argument(COMPLEX* number) {
    return atan(number->imaginary / number->real);
}