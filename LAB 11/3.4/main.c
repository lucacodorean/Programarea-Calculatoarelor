#include <stdio.h>
#include "student.h"

#define ERR_FILE_NOT_FOUND 404

int main(void) {

    STUDENT students[10];
    FILE* file = fopen("studenti.in", "r");

    if(file==NULL) {
        printf("Error - file not found.");
        return ERR_FILE_NOT_FOUND;
    }

    int count = 0;
    while(fscanf(file, "%s %s %f %f", students[count].nume, students[count].prenume, &students[count].bac, &students[count].mate)!=EOF) {count++;}
    fclose(file);

    file = fopen("studenti.out", "w");
    for(size_t i=0; i<count; i++) {
        calculate_admitere(&students[i]);
        fprintf(file, "Studentul se numeste %s %s\t si %s admis la facultate.\n", students[i].nume, students[i].prenume, students[i].admitere>=ADMITERE ? "este" : "nu este");
    }
    fclose(file);
    return 0;
}