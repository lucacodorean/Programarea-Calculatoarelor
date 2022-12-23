


#ifndef C_STUDENT_H
#define C_STUDENT_H

#include <stdio.h>

#define CHAR_LIMIT 255
#define ADMITERE 8.49

typedef struct {
    char nume[CHAR_LIMIT];
    char prenume[CHAR_LIMIT];
    float bac, mate, admitere;
} STUDENT;

void calculate_admitere(STUDENT *student);
void display_student(STUDENT *student);
#endif //C_STUDENT_H