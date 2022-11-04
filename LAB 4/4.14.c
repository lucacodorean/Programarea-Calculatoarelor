//
// Created by Luca Codorean on 10/30/2022.
//

#include <stdio.h>
#include <stdbool.h>

#define MAX 100
int s[MAX],a,b;

void write(int arr[], int k);
_Bool complete(int k);
void backtr(int arr[], int k);

int main(void) {
    int n,q;

    puts("Introduceti numarul de intrebari: ");
    scanf("%d", &n);
    puts("Introduceti numarul de seturi de intrebari: ");
    scanf("%d", &q);
    puts("Introduceti limitele de punctaje pentru intrebari: ");
    scanf("%d %d", &a, &b);

    int punctaj[n];

    for(int i = 0; i<n; i++) scanf("%d", &punctaj[i]);

    backtr(punctaj, 1);



    return 0;
}

void write(int arr[], int k){
    for(int i=1; i<=k; i++){
        printf("%d ", arr[s[i]]);
    }
    printf("\n");
}

_Bool complete(int k){
    return b==k;
}

void backtr(int arr[], int k){
    for(int i=s[k-1]+1; i<=a; ++i){
        s[k]=i;
        if(complete(k)==true){
            write(arr, b);
        }
        else backtr(arr, k+1);
    }
}
