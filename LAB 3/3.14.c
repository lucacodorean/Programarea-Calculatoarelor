//
// Created by Luca Codorean on 10/18/2022.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    double x,y;
    scanf("%lf %lf", &x, &y);
    double r = sqrt(pow(x,2)+pow(y,2));

    if(r==0) printf("Teta poate sa fie orice numar real.");
    else {
        printf("\nPe intervalul [0,2PI), valoarea lui teta este: ");
        if(x>0 && y>=0) printf("%lf.", atan2(y,x));
        if(x>0 && y<0) printf("%lf + 2PI.", atan2(y,x));
        if(x<0) if(x>0 && y<0) printf("%lf + PI.", atan2(y,x));
        if(x==0 && y>0) printf("PI/2.");
        if(x==0 && y<0) printf("3PI/2.");

        printf("\nPe intervalul (-PI,PI], valoarea lui teta este: ");
        if(x>0 && y>=0) printf("%lf.", atan2(y,x));
        if(x>0 && y<0) printf("%lf + PI.", atan2(y,x));
        if(x<0) if(x>0 && y<0) printf("%lf - PI.", atan2(y,x));
        if(x==0 && y>0) printf("PI/2.");
        if(x==0 && y<0) printf("-PI/2.");
    }
    return 0;
}