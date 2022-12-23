/*
3.7. De la tastatură se citesc partea reală şi partea imaginară pentru n numere complexe.
Să se creeze atât un fişier text cât și un fișier binar care conţin numerele complexe citite (partea
reală și partea imaginară) împreună cu modulele și argumentele lor
*/

#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main(void) {
    int count; puts("How many complex numbers do you want to enter?"); scanf("%d", &count);
    FILE* text = fopen("complex.txt", "w");
    FILE* bin = fopen("complex.bin", "wb");

    for(size_t i = 0; i<count; i++) {
        COMPLEX number;
        scanf("%f %f", &number.real, &number.imaginary);
        number.module   = set_module(&number);
        number.argument = set_argument(&number);
        fprintf(text, "Number %0.2f %s%0.2f*i are modulul %0.2f si argumentul %0.2f.\n", number.real, number.imaginary <0 ? "-" : "+", number.imaginary, number.module, number.argument);
        fwrite(&number, sizeof(COMPLEX), 1, bin);
    }

    fclose(text), fclose(bin);
    free(text), free(bin);
    text = bin = NULL;
    return 0;
}