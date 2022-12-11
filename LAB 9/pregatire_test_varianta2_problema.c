/**
* Scrieți funcția cuvant care construiește un cuvânt pe baza unei matrice care conține numai litere mari.
Cuvântul se construiește luând, în ordine, de pe fiecare coloană, litera care este alfabetic cea mai mare. Funcția
trebuie să aloce memorie pentru cuvântul care se construiește iar în final să îl dea prin intermediul unui parametru.
Funcția trebuie de asemenea să returneze numărul de vocale (AEIOU) pe care îl conține cuvântul construit
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cuvant(char[256][256], int, int, char*);
static char max(char a, char b) { return (a + '0' > b +'0' ?  a : b); }

int main(void) {
    char matrix[256][256] = {
            {'R','E','M','O','A'},
            {'N','C','S','T','C'},
            {'T','B','Q','P','E'}
    };

    int n = 5, m = 3;
    char *c = (char*)calloc(m,sizeof(char));
    int nr = cuvant(matrix,n,m,c);

    printf("%d\n%s", nr, c);
    free(c), c = NULL;
    return 0;
}

int cuvant(char matrix[256][256] ,int n, int m, char* result) {
   int vowels = 0, size = 0;

   for(int j=0; j<n; j++) {
       char to_be_added = '0';
       for(int i = 0; i<m; i++) {
            to_be_added = max(to_be_added, matrix[i][j]);
       }
       result[size++] = to_be_added;
   }

   for(size_t i = 0; i<strlen(result); i++) {
       if(strchr("AEIOU", result[i])==0) vowels++;
   }
   return vowels;
}