#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIRST 0
#define SECOND 1

static const size_t min(unsigned long a, unsigned long b) { return (a<b ? a : b); };
void swap( char* a, char* b);
const size_t distinct_characters(const char* arr);

int sort_by_length(const char* a, const char* b);
int lexicographic_sort(const char* a, const char* b);
int lexicographic_sort_reverse(const char* a, const char* b);
int sort_by_number_of_distinct_characters(const char* a, const char* b);
void string_sort(char** arr,int len,int (*cmp_func)(const char* a, const char* b));

int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    return 0;
}

int lexicographic_sort(const char* a, const char* b) {
    for(size_t i = 0; i < min(strlen(a), strlen(b));) {
        if (a[i] == b[i]) i++;
        else {
            if (a[i] < b[i]) return FIRST;
            else if (b[i] < a[i]) return SECOND;
        }
    }
    return FIRST;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    for(size_t i=0; i<min(strlen(a), strlen(b));) {
        if (a[i] == b[i]) i++;
        else {
            if (a[i] < b[i]) return SECOND;
            else if (b[i] < a[i]) return FIRST;
        }
    }
    return SECOND;
}

const size_t distinct_characters(const char* arr) {
    int ap[256] = {0}, number = 0;
    for(size_t i = 0; arr[i] != '\0'; i++) {
        ap[arr[i]]++;
    }
    for(size_t i = 'a'; i<='z'; i++) { number+=(ap[i] == 1 ? 1 : 0); }
    return number;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    size_t distinct_in_a = distinct_characters(a);
    size_t distinct_in_b = distinct_characters(b);

    if(distinct_in_a==distinct_in_b) {
        return lexicographic_sort(a,b);
    }
    else {
        if (distinct_in_a < distinct_in_b) return FIRST;
        else if (distinct_in_a > distinct_in_b) return SECOND;
    }
    return 0;
}
int sort_by_length(const char* a, const char* b) {
    size_t size_of_a = strlen(a);
    size_t size_of_b = strlen(b);
    if(size_of_a == size_of_b) return lexicographic_sort_reverse(a,b);
    else {
        if(size_of_a < size_of_b) return FIRST;
        if(size_of_a > size_of_b) return SECOND;
    }
    return -1;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *, const char *)) {
    for(size_t current_string = 0; current_string < len; current_string++) {
        for(size_t comparison_string = current_string + 1; comparison_string < len; comparison_string++) {
            int result = cmp_func(arr[current_string], arr[comparison_string]);
            if(result == 1) {
                swap(arr[current_string], arr[comparison_string]);
            }
        }
    }
}

void swap(char *a, char *b) {
    char* arr = malloc(min(strlen(a), strlen(b)) * sizeof(char));
    strcpy(arr,a); strcpy(a,b); strcpy(b,arr);
    free(arr);
}