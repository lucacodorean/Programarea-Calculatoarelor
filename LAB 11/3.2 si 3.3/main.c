#include <stdio.h>
#include <stdlib.h>
#include "product.h"

static unsigned int U_ID;

#define ERR_PATH_NOT_SPECIFIED 1
#define ERR_FILE_NOT_FOUND 404

enum bool {false, true};

void swap(PRODUCT*, PRODUCT*);
enum bool comparition_function(PRODUCT, PRODUCT);
void sort(PRODUCT*, int, enum bool (*)(PRODUCT, PRODUCT));

int main(int argc, char* argv[]) {

    if(argc < 2)  {
        printf("Error - no path and operatation mentioned.");
        return ERR_PATH_NOT_SPECIFIED;
    }

    FILE* file;
    file =  fopen(argv[1], argv[2]);

    if(file==NULL) {
        printf("Error - file not found.");
        return ERR_FILE_NOT_FOUND;
    }


    PRODUCT* products = (PRODUCT*)calloc(PRODUCTS_LIMIT,sizeof(PRODUCT));

    unsigned int count = 0;
    while(fscanf(file, "%s %s %f %f", products[count].name, products[count].measurment_unit, &products[count].price, &products[count].quantity) != EOF) {
        products[count++].unique_ID = U_ID++;
    } fclose(file);

    sort(products, count, comparition_function);

    file = fopen("products.out", "w");
    display_products(file, products, count);
    fclose(file);

    free(products);     products = NULL;
    free(file);         file = NULL;
    return 0;
}


enum bool comparition_function(PRODUCT first, PRODUCT second) {
    return first.unique_ID < second.unique_ID ? true : false;
}

void sort(PRODUCT* arr, int size, enum bool (*comparition_function)(PRODUCT, PRODUCT)) {
    for(size_t i = 1; i<size; i++) {
        if(comparition_function(arr[i], arr[i-1])==false) {
            swap(&arr[i], &arr[i-1]);
        }       
    }
}