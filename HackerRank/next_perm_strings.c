#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const void swap(char *first, char *second) {
    char* aux = &(*first);
    strcpy(first, second);
    strcpy(second, aux);
}

int next_permutation(char** string_arr, int n) {
    int i;
    if(n==1) {
        return 0;
    } else {
        i = n - 1;
        while (i > 0 && strcmp(string_arr[i - 1], string_arr[i]) >=0) {
            i--;
        }
        if (i == 0) return 0;
    }

    int j = i - 1;
    while(strcmp(string_arr[j], string_arr[i-1])<=0) {
        j--;
    }
    swap(string_arr[j], string_arr[i-1]);

    j = i - 1;
    while(i<j) {
        swap(string_arr[i], string_arr[j]);
        i++; j--;
    }
    return 1;
}

int main()
{
    char **s;
    int n;
    scanf("%d", &n);
    s = calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        s[i] = calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }
    do
    {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(s, n));
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}