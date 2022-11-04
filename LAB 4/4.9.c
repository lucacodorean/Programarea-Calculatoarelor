//
// Created by Luca Codorean on 10/25/2022.
//
#include <stdio.h>
#define MAX 20

struct Polynomial {
    char function_name, parameter;
    int size, coef[MAX];
};

const int max(int a, int b) { return a>b ? a : b; }
const int min(int a, int b) { return a<b ? a : b; }
void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}
void reverse(struct Polynomial function) {
    int i = 0, j = function.size-1;
    while(i<j) swap(&function.coef[i++], &function.coef[j--]);
}

void printPolynomial(struct Polynomial function) {
    struct Polynomial aux = function;
    reverse(aux);

    printf("%c(%c) = ", function.function_name, function.parameter);
    int j = aux.size-1;
    for(int i = 0; i<aux.size; i++) {
        printf("%d%c^%d%s ", aux.coef[i], aux.parameter, j--, (i != aux.size-1 ? (aux.coef[i] > 0 ? "+" : "-") : "\n"));
    }
}
struct Polynomial init_Polynomial(char function_name, char parameter, int size) {
    struct Polynomial function;
    function.function_name = function_name;
    function.parameter = parameter;
    function.size = size;
    for(int i = 0; i<MAX; i++) *(function.coef + i) = 0;

    return function;
}

struct Polynomial addPolynomial(struct Polynomial first_function, struct Polynomial second_function) {
    struct Polynomial result = init_Polynomial('R', 'x', max(first_function.size, second_function.size));
    for(int i = 0; i<result.size; i++) {
        result.coef[i] = first_function.coef[i] + second_function.coef[i];
    }
    return result;
}
struct Polynomial subtractPolynomial(struct Polynomial first_function, struct Polynomial second_function) {
    struct Polynomial result = init_Polynomial('R', 'x', max(first_function.size, second_function.size));
    for(int i = 0; i<result.size; i++) {
        result.coef[i] = first_function.coef[i] - second_function.coef[i];
    }
    return result;
}
struct Polynomial multiplyPolynomial_scalar(struct Polynomial first_function, int value) {
    struct Polynomial aux = first_function;
    for(int i = 0; i<aux.size; i++) {
        aux.coef[i] *= value;
    }
    return aux;
}
struct Polynomial multiplyPolynomial(struct Polynomial first_function ,struct Polynomial second_function) {
    struct Polynomial aux = init_Polynomial('A','x', second_function.size + first_function.size);
    for(int i = 0; i< first_function.size; i++) {
        for(int j = 0; j<second_function.size; j++) {
            aux.coef[i+j] += first_function.coef[i] * second_function.coef[j];
        }
    }
    return aux;
}
struct Polynomial dividePolynomial(struct Polynomial function, const int constant) {
    struct Polynomial result = init_Polynomial('A', 'x', function.size);
    *(result.coef) = *(function.coef);

    for(int i = 0; i<result.size; i++) {
        result.coef[i] = ( result.coef[i-1] * constant ) + function.coef[i];
    }

    return result;
}

int main() {
    int n,m; scanf("%d %d", &n, &m);
    n++, m++;

    struct Polynomial A = init_Polynomial('A', 'x', n);
    struct Polynomial B = init_Polynomial('B', 'x', m);

    A.function_name = 'A'; A.parameter = 'x';
    B.function_name = 'B'; B.parameter = 'x';

    for(int i = 0; i<A.size; i++) { scanf("%d", &A.coef[i]); }
    for(int i = 0; i<B.size; i++) { scanf("%d", &B.coef[i]); }

    printPolynomial(A);
    printPolynomial(B);

    struct Polynomial resultAddition = addPolynomial(A,B);
    resultAddition.parameter = 'x'; resultAddition.function_name = 'R';
    printPolynomial(resultAddition);

    struct Polynomial resultSubtraction = subtractPolynomial(A,B);
    resultSubtraction.parameter = 'x'; resultSubtraction.function_name = 'S';
    printPolynomial(resultSubtraction);

    struct Polynomial multipliedPolynomial = multiplyPolynomial_scalar(A,5);
    multipliedPolynomial.parameter = 'x'; multipliedPolynomial.function_name = 'M';
    printPolynomial(multipliedPolynomial);

    struct Polynomial multiplyTwoPolynomials = multiplyPolynomial(A,B);
    multiplyTwoPolynomials.parameter = 'x'; multiplyTwoPolynomials.function_name = 'M';
    printPolynomial(multiplyTwoPolynomials);

    struct Polynomial dividedPolynomial = dividePolynomial(A,5);
    dividedPolynomial.parameter = 'x'; dividedPolynomial.function_name = 'M';
    printPolynomial(dividedPolynomial);

    return 0;
}
