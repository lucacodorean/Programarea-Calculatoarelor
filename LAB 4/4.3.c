//
// Created by Luca Codorean on 10/31/2022.
//

#include <stdio.h>
#include <stdlib.h>

const float max(float first, float second);
const float min(float first, float second);

int main(void) {
    int n; scanf("%d", &n);
    float arr[n];

    for(size_t i = 0; i<n; i++) {
        scanf("%f", &arr[i]);
    }

    float maxVal=(float)INT_MIN; int maxPos = 0;
    float minVal=(float)INT_MAX; int minPos = 0;

    for(size_t i = 0; i<n; i++) {
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);

        if(maxVal == arr[i]) maxPos = i;
        if(minVal == arr[i]) minPos = i;
    }
    printf("Valoarea maxima este %f, iar ultima sa aparitie in array se afla la indexul %d.", maxVal, maxPos);
    printf("Valoarea minima este %f, iar ultima sa aparitie in array se afla la indexul %d.", minVal, minPos);

    return 0;
}

const float max(float first, float second) { return first < second ? second : first; }
const float min(float first, float second) { return first < second ? first : second; }