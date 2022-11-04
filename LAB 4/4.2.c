//
// Created by Luca Codorean on 10/27/2022.
//

#include <stdio.h>
#include <stdbool.h>

struct Point {
    int x, y;
};

struct Polygone {
    struct Point A,B,C,D;
    int L1, L2, L3, L4;
};

_Bool check90angle(struct Point A, struct Point B, struct Point C, struct Point D);
_Bool check0angle(struct Point first, struct Point second, struct Point third, struct Point fourth);
_Bool isRhombus(struct Polygone parameter);
_Bool isSquare(struct Polygone parameter);
_Bool isRectangle(struct Polygone parameter);
_Bool isParallelogram(struct Polygone parameter);
_Bool isTrapezoid(struct Polygone parameter);

int main(void) {
    struct Polygone poligon;
    puts("Introduceti coordonatele celor patru puncte: ");
    scanf("%d %d %d %d %d %d %d %d", &poligon.A.x, &poligon.A.y, &poligon.B.x, &poligon.B.y, &poligon.C.x, &poligon.C.y, &poligon.D.x, &poligon.D.y);
    printf("Punctele sunt: \n\tA(%d, %d)\nB(%d, %d)\nC(%d, %d)\nD(%d, %d)\n", poligon.A.x, poligon.A.y, poligon.B.x, poligon.B.y, poligon.C.x, poligon.C.y, poligon.D.x, poligon.D.y);
    if(isSquare(poligon)==true)         { puts("Poligonul este romb."); return 0; }
    else {
        if(isRhombus(poligon))          { puts("Poligonul este patrat."); return 0; }
        if(isRectangle(poligon))        { puts("Poligonul este dreptunghi."); return 0; }
        if(isParallelogram(poligon))    { puts("Poligonul este paralelogram."); return 0; }
        if(isTrapezoid(poligon))        { puts("Poligonul este trapez."); return 0; }
    }
    return 0;
}

_Bool check90angle(struct Point A, struct Point B, struct Point C, struct Point D) {
    double m1 = (A.y - B.y)/(double)(A.x - B.x);
    double m2 = (C.y - D.y)/(double)(C.x - D.y);

    return m1*m2 == -1 ? true : false;
}
_Bool check0angle(struct Point first, struct Point second, struct Point third, struct Point fourth) {
    double m1 = (first.y - second.y)/(double)(first.x - second.x);
    double m2 = (third.y - fourth.y)/(double)(third.x - fourth.y);

    return m1==m2 ? true : false;
}

_Bool isRhombus(struct Polygone parameter) {
    parameter.L1 = (parameter.A.x - parameter.B.x)*(parameter.A.x - parameter.B.x)  + (parameter.A.y - parameter.B.y)*(parameter.A.y - parameter.B.y);
    parameter.L2 = (parameter.B.x - parameter.C.x)*(parameter.B.x - parameter.C.x)  + (parameter.B.y - parameter.C.y)*(parameter.B.y - parameter.C.y);
    parameter.L3 = (parameter.C.x - parameter.D.x)*(parameter.C.x - parameter.D.x)  + (parameter.C.y - parameter.D.y)*(parameter.C.y - parameter.D.y);
    parameter.L4 = (parameter.D.x - parameter.A.x)*(parameter.D.x - parameter.A.x)  + (parameter.D.y - parameter.A.y)*(parameter.D.y - parameter.A.y);

    return parameter.L1 == parameter.L2 && parameter.L3 == parameter.L4 && parameter.L3 == parameter.L2 ? true : false;
}
_Bool isSquare(struct Polygone parameter) {
    return isRhombus(parameter)==true && check90angle(parameter.A, parameter.B, parameter.C, parameter.D)==true ? true : false;
}
_Bool isRectangle(struct Polygone parameter) {
    parameter.L1 = (parameter.A.x - parameter.B.x)*(parameter.A.x - parameter.B.x)  + (parameter.A.y - parameter.B.y)*(parameter.A.y - parameter.B.y);
    parameter.L2 = (parameter.B.x - parameter.C.x)*(parameter.B.x - parameter.C.x)  + (parameter.B.y - parameter.C.y)*(parameter.B.y - parameter.C.y);
    parameter.L3 = (parameter.C.x - parameter.D.x)*(parameter.C.x - parameter.D.x)  + (parameter.C.y - parameter.D.y)*(parameter.C.y - parameter.D.y);
    parameter.L4 = (parameter.D.x - parameter.A.x)*(parameter.D.x - parameter.A.x)  + (parameter.D.y - parameter.A.y)*(parameter.D.y - parameter.A.y);

    return parameter.L1 != parameter.L2 && parameter.L1 == parameter.L3  && parameter.L4 == parameter.L2 && check90angle(parameter.A, parameter.B, parameter.C, parameter.D)==true ? true : false;
}
_Bool isParallelogram(struct Polygone parameter) {
    parameter.L2 = (parameter.B.x - parameter.C.x)*(parameter.B.x - parameter.C.x)  + (parameter.B.y - parameter.C.y)*(parameter.B.y - parameter.C.y);
    parameter.L4 = (parameter.D.x - parameter.A.x)*(parameter.D.x - parameter.A.x)  + (parameter.D.y - parameter.A.y)*(parameter.D.y - parameter.A.y);
    return check0angle(parameter.B,parameter.C,parameter.D,parameter.A)==true && parameter.L2 == parameter.L4 && !isRhombus(parameter) && !isRectangle(parameter) && !isSquare(parameter) ? true : false;
}
_Bool isTrapezoid(struct Polygone parameter) {
    parameter.L1 = (parameter.A.x - parameter.B.x)*(parameter.A.x - parameter.B.x)  + (parameter.A.y - parameter.B.y)*(parameter.A.y - parameter.B.y);
    parameter.L3 = (parameter.C.x - parameter.D.x)*(parameter.C.x - parameter.D.x)  + (parameter.C.y - parameter.D.y)*(parameter.C.y - parameter.D.y);
    return check0angle(parameter.A, parameter.B, parameter.C, parameter.D) == true && parameter.L1 != parameter.L3 ? true : false;
}