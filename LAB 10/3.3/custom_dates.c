//
// Created by Luca Codorean on 12/17/2022.
//

#include "custom_dates.h"
#include <stdio.h>
#include <stdlib.h>

void printfd(DATE);
DATE * init_date();
void updated(DATE*, unsigned short, unsigned short, unsigned short);


DATE * init_date() {
    DATE* parameter = (DATE*)malloc(sizeof(DATE));
    printf("Introduceti o data sub formatul mm/dd/yyyy: "); scanf("%hd/%hd/%hd", &parameter->month, &parameter->day, &parameter->year);
    return parameter;
}
void printfd(DATE parameter) {
    printf("%hd/%hd/%hd",parameter.month, parameter.day, parameter.year);
}

void updated(DATE* parameter, unsigned short day, unsigned short month, unsigned short year) {
    parameter->day = day;
    parameter->month = month;
    parameter->year = year;
}
