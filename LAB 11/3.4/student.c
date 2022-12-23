#include "student.h"

void calculate_admitere(STUDENT *student);
void display_student(STUDENT *student);

void calculate_admitere(STUDENT *student) {
    student->admitere = (student->bac*0.2 + student->mate*0.8);
}

// display_student function
void display_student(STUDENT *student) {
    printf("Studentul se numeste %s %s\t are media de admitere %f.\n", student->nume, student->prenume, student->admitere);
}
