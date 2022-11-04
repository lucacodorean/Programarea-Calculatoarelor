#include <stdio.h>

/**
 *  Sa se genereze toate numerele <= cu n; n = numar natural.
 *  Pentru o varianta eficienta se poate utiliza ciurul lui Eratostene.
 *  Algoritmul este eficient pentru un n cu o valoare rezonabila.
 *
 *      freq[nr] == 0 ? nr este prim : nr nu este prim.
 *
 *      O implementare a ciurului este:
 *          1) marcam toate numerele de la 0 la limita cu 0, presupunand ca sunt prime.
 *          2) Ii scoatem pe 0 si 1 din lista, ele fiind neprime.
 *          3) Pentru numerele de la 2 la radicalul limitei marcam divizorii.
 */

void Eratostenes(int limit);
void print(int arr[], int size);

int main(void) {
    int limit;
    puts("Intoruceti limita sirului de numere prime: ");
    scanf("%d", &limit);

    Eratostenes(limit);

    return 0;
}

void print(int arr[], int size) {
    for(int i = 0; i<=size; i++) if(arr[i]==0) printf("%d ", i);
}

void Eratostenes(int limit) {
    int freq[limit+1];
    for(int i = 1; i<=limit; i++) freq[i] = 0;
    freq[0] = 1;
    freq[1] = 1;

    for(int i = 2; i*i<=limit; i++) {
        for(int j = 2; j<=limit/i; j++) freq[i*j] = 1;
    }

    print(freq,limit);
}

