# NOTITE C
________________
 
## Observatii

1) 11/0 -> inf 
2) 11/0.0 - 8/0.0 -> not a number (NaN)
3) NaN == NaN -> false 

### scanf()
    scanf("%d") -> este capabil să ignore whitespaces.
    scanf("%*d") -> se citeste o valoare fără a folosi o variabilă.

    Functionează pentru %d %f %lf %s 
    
    (!) Citire unui char dupa mai multe valori necesita mai multa atentie:
            Variante: scanf("%*c%c") -> un spatiu liber in buffer, dupa care se citeste corect;
                      scanf(" %c") sau scanf("\n%c")``

### switch 
    switch (conditie)
        case value:
                (!) break;
        case value2:
        ...
1) Instructiunea ``switch``, daca intra pe un caz, executa toate cazurile pana la intalnirea unui break.

### functii
    transmiterea unei valori prin adresa: se folosesc pointeri (vezi labul 5, numere_mari -> linux)

### macrouri si constante simbolice

(!) ***CONSTANTELE SI MACRO-URILE INLOCUIESC APELUL CU TEXTUL PE CARE-L DESCRIU.***

Fisierele header descarca in program signaturile subprogramelor scrise in fisierele header.
Se compileaza in etapa de preprocesare, impreuna cu descarcarea fisierelor header.

- CONST: #define nume valoare
- MACRO: #define nume(params)  { instructiuni } 

#### *functii vs macro*
``functia`` presupune apel si executia instructiunilor din corpul functiei. (tipul trebuie luat in considerare);

``macro`` presupun inlocuirea apelului cu text-ul macro-ului.


!!! Timpul de procesare este mai scurt cand folosim ``macro`` in detrimetul unei ``functii``.


#### *compilarea conditionata*

Directivele folosite sunt: `#if #ifdef, #ifndef, #else`

Directiva`#if`

```cpp
#if expr
text
#else
text
#endif
```

Directiva`#ifdef / #ifndef`
```cpp
#if NUME -> macro sau constanta simbolica.
    text
#else
    text
#endif
```
#### garda
Se pune de obicei la inceputul fiecarui fisier header. Practica pentru a evita incluziunea multipla a modulelor, in programarea modulara.

```cpp
#ifndef _MODUL_H
    #define _MODUL_H 
    ... // continutul unui fisier header.
#endif
```

### erori
Conectam o eroare cu compilatorul, in etapa de preprocesare.

```cpp
#ifndef __cplusplus
    #error text
#endif
```

## **MODULE**

1) partea ``publica`` este modulul cu extensia .h:
   1) • Conține definiții de structuri de date și funcții care sunt utilizate în afara modulului
2) partea ``privata`` contine extensia .c si contine:
   1) • Tot ce se află în interiorul unui modul este privat
   2) • Tot ce nu trebuie folosit direct din exteriorul unui modul trebuie să fie păstrat privat

```cpp
/*module1.h – Exemplu de fisier header pentru modulul "module1"
Informatii generale despre modul*/

#ifndef _MODULE1_H_
#define _MODULE1_H_

/* Includerea bibliotecilor necesare pentru declaratiile ce urmeaza */
#include <stdlib.h>
#include <math.h>
#include "altFisierHeader.h"
/* Declaratii de constante */
/* Declaratii de tipuri */
/* Declaratii de variabile globale */
/* Prototipuri de functii */
#endif
```

### **TIPURI DE VARIABILE**
#### variabile externe  ->  permit folosirea lor dintr-un modul in altul.
#### variabilele statice -> Sunt alocate de catre compilator intr-o zona speciala.

### **POINTERI**

**(!) POINTERII TREBUIE DECLARATI CU O VALOARE.**

*MOTIV: Nu putem sa indicam spre o adresa de memorie care nu are o valoare alocata.*

| tip                  | pointeri constanti la valori constante                                | pointeri la valori constante                                  | pointer constanti                                        |
|----------------------|-----------------------------------------------------------------------|---------------------------------------------------------------|----------------------------------------------------------|
| ce este?             | Nici pointerul, si nici valoarea asociata lui **NU** se pot schimba.  | Valoarea asociata pointerului **NU** se poate schimba         | Adresa lor **NU** se poate modifica.                     |
| declarare            | const tip* const identificator=valoare;                               | tip const *identificator;                                     | tip* const indentificator;                               |
| exemplu              | double z = 4.52; const double* x = &z; double y = 3.89;               | double z = 4.52; const double* const x = &z; double y = 3.89; | double z = 4.52; double* const x = &z;  double y = 3.89; |
| atribuire imposibila | *x = y;                                                               | *x = y; (nu se poate schimba valoarea lui x)                  | x = &y;                                                  |
| atribuire posibila   | IMPOSIBIL PENTRU CA, NICI ADRESA SI NICI VALOAREA NU SE POT MODIFICA. | x = &y; (se poate modifica adresa lui x)                      | *x = y;                                                  |

