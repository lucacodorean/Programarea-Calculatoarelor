//
// Created by Luca Codorean on 12/17/2022.
//

#ifndef C_STUDENT_H
#define C_STUDENT_H

#include "custom_dates.h"
#include <stdbool.h>

typedef struct {
    unsigned int ID;
    char* email;
    char* password;
    char* username;
    char* address;
    DATE* birthday;

} STUDENT;

STUDENT* init_student();
void printfs(STUDENT*);
void frees(STUDENT*);

#endif //C_STUDENT_H
