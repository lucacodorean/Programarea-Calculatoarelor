//
// Created by Luca Codorean on 11/6/2022.
//

#ifndef C_MULTIME_H
#define C_MULTIME_H

    #define CAPACITY 100
    typedef struct {
            float elemente[CAPACITY];
            int cardinal;
    } Multime;

    void printm(Multime);
    void sorteaza_multime(Multime*, char );
    void adauga_in_multime(float, Multime*);
    Multime intersectie(Multime, Multime);
    Multime reuniune(Multime, Multime);
    Multime diferenta(Multime, Multime);
#else
    #error "Eroare: Header deja incarcat."
#endif //C_MULTIME_H
