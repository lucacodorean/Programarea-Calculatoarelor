//
// Created by Luca Codorean on 10/26/2022.
//

#include <stdio.h>

int binary_search(double arr[], int size, double element) {
    int left = 0, right = size -1;
    while(left < right) {
        if(element == arr[size/2]) return size/2;
        else {
            if (element < arr[size/2]) right--;
            else if (element > arr[size/2]) left ++;
        }
    }

    return -1;
}

int main(void) {
    puts("Introduceti masura array-ului: ");
    int n; scanf("%d", &n);
    double arr[n+1];

    puts("\nIntroduceti valorile din array: ");
    for(int i = 0; i<n; i++) scanf("%lf", (arr+i));


    double element;
    puts("\nIntroduceti elementul cautat: ");
    scanf("%lf", &element);

    int binary_search_result = binary_search(arr, n, element);
    printf("Elementul %lf %s", element, (binary_search_result==-1 ? "nu se gaseste in sir" : "se gaseste in sir."));
    if(binary_search_result!=-1) printf(" El se afla la pozitia %d.", binary_search_result);
    return 0;
}