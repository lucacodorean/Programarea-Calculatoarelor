//
// Created by Luca Codorean on 12/7/2022.
//

/**
* (4p) Scrieți în C funcția litere care construiește o matrice de litere mici pe baza unui șir de valori dat care conține
numai numere naturale între 1 și 26. Matricea va avea numărul de linii identic cu numărul de elemente din șirul
de valori dat (o linie pentru fiecare element). Fiecare linie a matricei va avea un număr de elemente egal cu
valoarea corespunzătoare din șirul de valori dat și va conține repetarea literei care apare în alfabet pe poziția dată
de acea valoare din șirul dat.
Funcția trebuie să aloce mai întâi memorie (fără a face risipă!) pentru matricea care se construiește iar în final să
o returneze. Funcția trebuie de asemenea să ofere prin intermediul ultimului parametru, numărul total de consoane
din matrice. Nu este permisă utilizarea de variabile globale! Se presupune că toate datele de intrare sunt valide.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** litere(int*,int,int*);

int main(void) {
    int n = 5; int* consoane = (int*) calloc(1,sizeof(int));
    int arr[] = {3,4,1, 4, 6};

    char** mat = litere(arr,n,consoane);

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<arr[i]; j++) printf("%c, ",mat[i][j]);
        printf("\n");
    }

    printf("%d", *consoane);

    free(mat), mat = NULL;
    free(consoane), consoane = NULL;
    return 0;
}

char** litere(int* arr,int size,int* consoane) {
    (*consoane) = 0;

    char** result = (char**)calloc(size, sizeof(char*));
    for(int i = 0; i<size; i++) {
        result[i] = (char*)calloc(arr[i], sizeof(char));

    }
    for(int i = 0; i<size; i++) {
        int fill = (int)('a'+arr[i]-1);
        for(int j = 0; j<arr[i]; j++) result[i][j] = (char)fill;
    }

    for(int i = 0; i<size; i++) {
        for(int j = 0; j<arr[i]; j++) {
            if(!strchr("aeiou", result[i][j])) (*consoane)++;
        }
    }

    return result;
}