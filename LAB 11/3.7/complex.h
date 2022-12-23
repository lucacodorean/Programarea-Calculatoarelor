
#ifndef C_COMPLEX_H
#define C_COMPLEX_H

#include <stdio.h>

typedef struct {
    float imaginary, real, module, argument;
} COMPLEX;

float set_module(COMPLEX*);
float set_argument(COMPLEX*);
#endif // C_COMPLEX_H