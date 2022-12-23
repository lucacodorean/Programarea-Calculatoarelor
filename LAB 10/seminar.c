//
// Created by Luca Codorean on 12/15/2022.
//


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct TUPLE{
    int i, j, value;
};

typedef struct {
    int rows, columns, elements_no;
    struct TUPLE *tuple;
} MATRIX;

MATRIX * init_matrix();
bool possible(MATRIX, MATRIX);
MATRIX* sum(MATRIX, MATRIX);
struct TUPLE* correspondent(struct TUPLE *pTuple, MATRIX b);
void dealloc(MATRIX*);
void display(MATRIX);

int main(void) {

    MATRIX* A = init_matrix();
    MATRIX* B = init_matrix();
    MATRIX* C = sum(*A,*B);

    display(*C);
    dealloc(A);
    dealloc(B);
    return 0;
}

MATRIX * init_matrix() {
    MATRIX* result = (MATRIX*)malloc(sizeof(MATRIX));
    printf("Introduceti numarul de linii: ");                    scanf("%d", &result->rows);
    printf("Introduceti numarul de coloane: ");               scanf("%d", &result->columns);
    printf("Introduceti numarul de elemente nenule: ");       scanf("%d", &result->elements_no);

    result->tuple = (struct TUPLE*) calloc(result->elements_no, sizeof(struct TUPLE));

    printf("Introduceti triplete de forma (linie, coloana, value):\n");
    for(size_t i = 0; i<result->elements_no; i++) {
        scanf(" (%d,%d,%d)", &result->tuple[i].i, &result->tuple[i].j, &result->tuple[i].value);
    }
    return result;
}

bool possible(MATRIX A, MATRIX B) {
    return A.columns == B.columns &&  A.rows == B.rows;
}

struct TUPLE* correspondent(struct TUPLE *pTuple, MATRIX pMatrix) {
    for(size_t i = 0; i<pMatrix.elements_no; i++) {
        if(pMatrix.tuple[i].i == pTuple->i && pMatrix.tuple[i].j == pTuple -> j) return pMatrix.tuple + i;
    }
    return NULL;
}


MATRIX* sum(MATRIX A, MATRIX B) {
    if(possible(A,B)==false) return NULL;

    MATRIX* result  = (MATRIX*)malloc(sizeof(MATRIX));
    result->columns = A.columns;
    result->rows    = B.rows;
    result->elements_no = B.elements_no + A.elements_no;

    result->tuple = (struct TUPLE*)calloc(result->elements_no, sizeof(struct TUPLE));
    int l = 0;
    for(size_t i = 0; i<result->elements_no; i++) {
        struct TUPLE* aux_2 = correspondent(&A.tuple[i], B);
        if(aux_2 != NULL)  {
            result->tuple[l].i = A.tuple[i].i;
            result->tuple[l].j = A.tuple[i].j;
            result->tuple[l].value = A.tuple[i].value + aux_2->value;
        } else {
            result->tuple[l].i = A.tuple[i].i;
            result->tuple[l].j = A.tuple[i].j;
            result->tuple[l].value = A.tuple[i].value;
        }
        l++;
    }

    for(size_t i = 0; i<result->elements_no; i++) {
        struct TUPLE* aux_2 = correspondent(&B.tuple[i], A);
        if(aux_2==NULL) {
            result->tuple[l].i = B.tuple[i].i;
            result->tuple[l].j = B.tuple[i].j;
            result->tuple[l].value = B.tuple[i].value;
            l++;
        }
    }

    return result;
}

void display(MATRIX parameter) {
    for(size_t i = 0; i<parameter.elements_no; i++) printf("(%d, %d, %d)\n",parameter.tuple[i].i,parameter.tuple[i].j,parameter.tuple[i].value);
}

void dealloc(MATRIX* parameter) {
    free(parameter->tuple);
    free(parameter);
    parameter = NULL;
}