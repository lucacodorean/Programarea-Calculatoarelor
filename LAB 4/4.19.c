//
// Created by Luca Codorean on 10/30/2022.
//
#include <string.h>
#include <stdio.h>
#define LIMIT 256

const unsigned int max(unsigned int a, unsigned int b) { return a<b ? b : a; }

int main(void) {
    unsigned int maximum_strlen = 1, words_counter = 0;
    char sentence[LIMIT];
    scanf("%[^\n]s", sentence);

    char *word = strtok(sentence, " .");
    while(word!=NULL) {
        maximum_strlen = max(maximum_strlen, strlen(word));
        words_counter++;
        word = strtok(NULL, " .");
    }

    printf("Propozitia citita are %d cuvinte, iar cel mai lung cuvant are %d litere.", words_counter, maximum_strlen);
    return 0;
}