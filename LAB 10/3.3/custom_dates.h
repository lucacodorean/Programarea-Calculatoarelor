//
// Created by Luca Codorean on 12/17/2022.
//

#ifndef C_CUSTOM_DATES_H
#define C_CUSTOM_DATES_H

typedef struct {
    unsigned short day, month, year;
} DATE;

void printfd(DATE);
DATE* init_date();
void updated(DATE*, unsigned short, unsigned short, unsigned short);

#endif //C_CUSTOM_DATES_H
