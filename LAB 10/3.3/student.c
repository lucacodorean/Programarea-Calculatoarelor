//
// Created by Luca Codorean on 12/17/2022.
//


#include "student.h"
#include <stdio.h>
#include <stdlib.h>

#define ADDRESS_LIMIT 50
#define CHAR_LIMIT 30

static unsigned int ID = 1;

STUDENT * init_student();
void printfs(STUDENT*);
void frees(STUDENT*);

STUDENT * init_student() {
    STUDENT* result  = (STUDENT*) malloc(sizeof(STUDENT));
    result->address  = (char*)calloc(ADDRESS_LIMIT, sizeof(char));
    result->username = (char*)calloc(CHAR_LIMIT, sizeof(char));
    result->email    = (char*)calloc(CHAR_LIMIT, sizeof(char));
    result->password = (char*)calloc(CHAR_LIMIT, sizeof(char));

    result->ID = (ID++);
    printf("Introduceti numele studentului: "); scanf("%s", result->username);          fflush(stdin);
    printf("Introduceti email-ul studentului: "); scanf("%s", result->email);           fflush(stdin);
    printf("Introduceti parola studentului: "); scanf("%s", result->password);          fflush(stdin);
    printf("Introduceti adresa studentului: "); scanf("\n%[^\n]", result->address);
    result->birthday = init_date();
    fflush(stdin);

    printf("\nStudentul cu ID: %u s-a inregistrat cu succes.\n",ID-1);
    return result;
}

void printfs(STUDENT* parameter) {
    printf("Student ID: %u \n\tNume student: %s", parameter->ID, parameter->username);
    printf("\n\tEmail student: %s\n\tAdresa studentului: %s\n", parameter->email, parameter->address);
}

void frees(STUDENT* parameter) {
    free(parameter->address);   parameter->address  = NULL;
    free(parameter->email);     parameter->email    = NULL;
    free(parameter->username);  parameter->username = NULL;
    free(parameter->password);  parameter->password = NULL;
    free(parameter);            parameter           = NULL;
}
