/*
 * Fisierul header contine doar declaratii de constante si prototipurile functilor date spre folosinta utilizatorului.
 * Numere complexe:
 *          1) adunare / scadere
 *          2) inmultire / impartire
 *          3) forma trigonometrica
 */

#ifndef COMPLEX_H_INCLUDED
    #define COMPLEX_H_INCLUDED

    struct Complex {
        float real, imaginar;
        float module;
        float PHI;
        /**
         * Forma trigo: z = r(cos_PHI+i*sin_PHI);
         * r > 0, PHI apartine [0,2*MATH_PI)
         * r = module
         */
    };

    void display(struct Complex parameter);
    void set_module(struct Complex* parameter);
    void set_PHI(struct Complex* parameter);
    void display_forma_trigonometrica(struct Complex parameter);
    struct Complex aduna(struct Complex first, struct Complex second);
    struct Complex scade(struct Complex first, struct Complex second);
    struct Complex inmulteste(struct Complex first, struct Complex second);
    struct Complex imparte(struct Complex first, struct Complex second);

#include "complex.c"
#endif // COMPLEX_H_INCLUDED


