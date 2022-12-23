//
// Created by Luca Codorean on 12/12/2022.
//

#include <stdio.h>
#include <string.h>

enum zodiac {Capricon, Varsator, Pesti, Berbec, Taur, Gemeni, Rac, Leu, Fecioara, Balanta, Scorpion, Sagetator};

struct Student{
    char nume[25], adresa[50];
    unsigned int varsta;
    float medie;
    enum zodiac zodie;
} Ion; /// Ion

const char* numeZodie(enum zodiac zodii) {
    switch (zodii) {
        case 0: return "Capricorn";
        case 1: return "Varsator";
        case 2: return "Pesti";
        case 3: return "Berbec";
        case 4: return "Taur";
        case 5: return "Gemeni";
        case 6: return "Rac";
        case 7: return "Leu";
        case 8: return "Fecioara";
        case 9: return "Balanta";
        case 10: return "Scorpion";
        case 11: return "Sagetator";
        default: return "Prost";
    }
}


void readStudent(struct Student* parameter) {
    puts("Care e numele tau?"); scanf("%s", parameter->nume);
    puts("Cati ani ai?");       scanf("%u", &parameter->varsta);
    puts("Unde locuiesti?");    scanf("\n%[^\n]", parameter->adresa);
    puts("Ce medie ai?");       scanf("%f", &parameter->medie);
};

void printStudent(struct Student parameter) {
    printf("\nEl este %s. Are %u ani si locuieste la adresa: %s. Are media %0.2f.", parameter.nume, parameter.varsta, parameter.adresa, parameter.medie);
}

int main(void) {
    struct Student Andrei;
    readStudent(&Andrei);
    printStudent(Andrei);
    Ion = Andrei;
    strcpy(Ion.nume, "Ion");
    printStudent(Ion);
    return 0;
}