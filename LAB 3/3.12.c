//
// Created by Luca Codorean on 10/18/2022.
//

#include <stdio.h>
#include <math.h>

struct Point {
    int x,y;
};

struct Dreapta {
    int l;
    struct Point X,Y;
};

struct Cerc {
    struct Point centru;
    int raza;
};

const int herron(struct Dreapta A, struct Dreapta B, struct Dreapta C) {
    int p = (A.l + B.l + C.l)/2; return sqrt(p*(p-A.l)*(p-B.l)*(p-C.l));
}

const int get_h(int arie, struct Dreapta d) { return (arie*2)/d.l; }

int main() {
    struct Point A, B;
    struct Cerc C;
    scanf("%d %d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.centru.x, &C.centru.y, &C.raza);

    struct Dreapta OA, OB, AB;
    OA.X = A;
    OA.Y = C.centru;
    OA.l = sqrt(pow((OA.X.x - OA.Y.x),2) + pow((OA.X.y - OA.Y.y),2));

    OB.X = B;
    OB.Y = C.centru;
    OB.l = sqrt(pow((OB.X.x - OB.Y.x),2) + pow((OB.X.y - OB.Y.y),2));

    AB.X = A;
    AB.Y = B;
    AB.l = sqrt(pow((AB.X.x - AB.Y.x),2) + pow((AB.X.y - AB.Y.y),2));

    int lungime_inaltime = get_h(herron(OA,OB,AB),AB);

    if(lungime_inaltime > C.raza) { printf("Dreapta determinata de punctele A,B nu apartine cercului dat."); }
    else {
        if(lungime_inaltime == C.raza) {printf("Dreapta determinata de punctele A,B este tangent la cercului dat."); }
        else if (lungime_inaltime <C.raza) { printf("Dreapta determinata de punctele A,B apartine cercului dat."); }
    }

    return 0;
}