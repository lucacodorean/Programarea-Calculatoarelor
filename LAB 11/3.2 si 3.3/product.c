#include "product.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_product(FILE* dest, PRODUCT parameter) {
    fprintf(dest, "| %hd  | %*s | %*s | %s%6.2f | %s%6.2f%s |\n", parameter.unique_ID, CHAR_LIMIT, parameter.name, 3, parameter.measurment_unit,
     parameter.price<100 ? " " : "", parameter.price, 
     parameter.quantity<1000? " ": "", parameter.quantity, parameter.quantity<=9999? "   ": "  ");
}

void display_products(FILE* dest, PRODUCT* arr, size_t size) {

    fprintf(dest, "---------------------------------------------------------------\n");
    fprintf(dest, "| ID |    DENUMIREA PRODUSLUI    | U.M |  PRICE  |  QUANTITY  |\n");
    fprintf(dest, "|----|---------------------------|-----|---------|------------|\n");

    for(int i = 0; i<size; i++) {
        display_product(dest, arr[i]);
    }
    fprintf(dest, "---------------------------------------------------------------\n");
}

void swap(PRODUCT* first, PRODUCT* second) {
    PRODUCT* aux = (PRODUCT*)malloc(sizeof(PRODUCT)+1);
    memcpy(aux, first, sizeof(PRODUCT));
    memcpy(first, second, sizeof(PRODUCT));
    memcpy(second, aux, sizeof(PRODUCT));
    free(aux);
}