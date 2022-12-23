#ifndef C_PRODUCT_H
#define C_PRODUCT_H

#include <stdio.h>

#define CHAR_LIMIT      25
#define PRODUCTS_LIMIT  100
#define PRICE_LIMIT     99999.99

typedef struct {
        char name[CHAR_LIMIT];
        char measurment_unit[3];
        unsigned int unique_ID;
        float price, quantity;
    } PRODUCT;

void display_product(FILE*, PRODUCT);
void display_products(FILE*, PRODUCT*, size_t);
void swap(PRODUCT*, PRODUCT*);

#endif // C_PRODUCT_H