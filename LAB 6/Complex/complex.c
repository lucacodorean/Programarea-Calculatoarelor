//
// Created by Luca Codorean on 11/5/2022.
//

#include <stdio.h>
#include <math.h>
#include "complex.h"

static int get_k_value(struct Complex parameter) {
    int k = 0;
    if(parameter.real < 0 && parameter.imaginar >= 0) k = 0;
    else if(parameter.real < 0) k = 1;
    else if(parameter.real > 0 && parameter.imaginar < 0) k = 2;

    return k;
}

void display(struct Complex parameter) { printf("%0.2f %c %0.2f*i", parameter.real, parameter.imaginar>=0 ? '+' : '-', parameter.imaginar); }
void set_module(struct Complex* parameter) { parameter->module = sqrtf((parameter->real*parameter->real) + (parameter->imaginar*parameter->imaginar)); }
void set_PHI(struct Complex* parameter) { parameter->PHI = atan2f(parameter->imaginar, parameter->real); }

void display_forma_trigonometrica(struct Complex parameter) {
    int k = get_k_value(parameter);
    printf("Forma trigonometrica este: z = %0.2f*(cos(%0.2f) + sin(%0.2f))", parameter.module, parameter.PHI, parameter.PHI);
    if(k) printf("%d*PI", k);
}

struct Complex aduna(struct Complex first, struct Complex second) {
    struct Complex result;
    result.real = first.real + second.real;
    result.imaginar = first.imaginar + second.imaginar;
    return result;
}
struct Complex scade(struct Complex first, struct Complex second) {
    struct Complex result;
    result.real = first.real - second.real;
    result.imaginar = first.imaginar - second.imaginar;
    return result;
}
struct Complex inmulteste(struct Complex first, struct Complex second) {
    struct Complex result;
    result.real = (first.real*first.imaginar) - (second.real*second.imaginar);
    result.imaginar = (first.real * second.imaginar) + (first.imaginar*second.real);
    return result;
}
struct Complex imparte(struct Complex first, struct Complex second) {
    struct Complex result;
    float numitor = (first.module*first.module) + (second.module*second.module);
    result.real = ((first.real * first.imaginar)+ (second.real * second.imaginar))/numitor;
    result.imaginar = ((first.imaginar + second.real)+ (first.real * second.imaginar))/numitor;
    return result;
}