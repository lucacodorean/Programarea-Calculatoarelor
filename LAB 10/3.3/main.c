//
// Created by Luca Codorean on 12/17/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"

void init_array(STUDENT**, int);
void print_array(STUDENT**,int);
void free_multiple_students(STUDENT**, int);
bool try_login(char* email, char*password, int size, STUDENT** student_list);

static bool correct(char* scr, char* comparition_string) { return stricmp(scr, comparition_string)==0; }


int main(void) {

    int size;
    printf("Introduceti numarul studentilor: "); scanf("%d", &size);
    STUDENT** students = (STUDENT**) calloc(size, sizeof(STUDENT*));

    init_array(students, size);
    print_array(students, size);

    char* email = "luca@gmail.com";
    char* password = "pass";

    printf("%s", try_login(email, password,size,students)==true ? "V-ati conectat cu succes." : "Datele introduse sunt incorecte.");

    free_multiple_students(students, size);
    return 0;
}

void init_array(STUDENT** parameter, int size) {
    for(size_t i = 0; i<size; i++) {
        parameter[i] = (STUDENT*) malloc(sizeof(STUDENT));
    }
    for(size_t i = 0; i<size; i++) parameter[i] = init_student();
}
void print_array(STUDENT** parameter, int size) {
    printf("\n\t\t--------------------------------\n");
    for(size_t i = 0; i<size; i++) {
        printfs(parameter[i]);
        printf("\n");
    }
    printf("\n\t\t--------------------------------\n");
}

void free_multiple_students(STUDENT** parameter, int size) {
    for(size_t i = 0; i<size; i++) {
        frees(parameter[i]);
    }
}

bool try_login(char* email, char*password, int size, STUDENT** student_list)
{
    for(size_t i = 0; i<size; i++) {
        if(correct(student_list[i]->email, email)==true && correct(student_list[i]->password, password)==true) return true;
    }
    return false;
}