//
// Created by Luca Codorean on 11/28/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int binary_search(double, const double*, int, int);
_Bool correct(const double*, int);

int main(void) {
    int size;
    puts("Introduceti numarul de elemente al array-ului: "); scanf("%d", &size);
    double* array = (double*)calloc(size, sizeof(double));

    puts("Introduceti elementele array-ului (in ordine crescatorare).");
    for(int i = 0; i<size; i++) scanf("%lf", array+i);

    if(correct(array, size)==true) {
        double element;
        puts("Introduceti valoare elementului cautat."); scanf("%lf", &element);
        int found =  binary_search(element, array, 0, size);
        if(found!=-1) printf("Elementul %0.2lf se afla pe pozitia %d.", element, found);
        else printf("Elementul %0.2lf nu a fost gasit in array.", element);
    } else printf("Elementele din array nu sunt ordonate crescator.");

    free(array), array = NULL;
    return 0;
}

int binary_search(double element, const double* array, int left, int right) {
    int middle = (left+right)/2;
    if(element == *(array+middle)) return middle;
    else if(left != right) {
        if(element < *(array+middle)) return binary_search(element, array, left++, middle);
        if(element > *(array+middle)) return binary_search(element, array, middle, right--);
    }

    return -1;
}

_Bool correct(const double* array, int size) {
    double previous = *array;

    for(int i = 1; i<size; i++) {
        if(previous > *array+i) return false;
        previous = *array+i;
    }

    return true;
}
