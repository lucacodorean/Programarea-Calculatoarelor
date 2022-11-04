//
// Created by Luca Codorean on 10/27/2022.
//

#include <stdio.h>
#include <string.h>

int getIndex(char** map, char sequence[], int size) {
    for(int i = 0; i<16; i++) {
        char current_sequence[5]; strcpy(current_sequence, map[i]);
        if(strcmp(current_sequence, sequence)==0) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int number;
    printf("Introduceti un numar in baza 10. Programul va returna corespondentul acestuia in baza 16. n = ");
    scanf("%d", &number);

    char hex[16] =
            {
                    '0', '1', '2', '3', '4', '5', '6', '7', '8',
                    '9', 'A', 'B', 'C', 'D', 'E', 'F'
            };

    char* binary_rep[16] =
            {
                "0000", "0001", "0010", "0011", "0100",
                "0101", "0110", "0111", "1000", "1001",
                "1010", "1011", "1100", "1101", "1110", "1111"
            };

    int p = 0;
    char binary[32];

    for(int i = 0; i<32; i++) binary[i] = '0';

    while(number>0) {
        binary[p++] = number%2 ? '1' : '0';
        number/=2;
    }

    printf("0x");
    for(int i = 31; i>=0; i-=4) {
        char current_sequence[5] = {binary[i], binary[i-1], binary[i-2], binary[i-3]};
        printf("%c", hex[getIndex(binary_rep, current_sequence, 4)]);
    }

    return 0;
}
