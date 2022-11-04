/*Realizați schema logică și descrierea în limbaj pseudocod pentru calculul și afișarea rădăcinilor reale/complexe ale ecuației de gradul doi aX^2+bX+c=0.
Valorile coeficienților a, b, c se citesc și sunt numere reale.*/

#include <stdio.h>
#include <math.h>

const double get_delta(double a, double b, double c) { return (b*b)-(4*a*c); }
void get_solutions(double a, double b, double c, double delta, int situation);
int analyse_data(double a, double b, double c);

int main() {

    double a, b, c;
    scanf("%lf %lf %lf", &a,&b,&c);
    get_solutions(a, b, c,get_delta(a,b,c), analyse_data(a,b,c));
    return 0;
}

int analyse_data(double a, double b, double c) {
    if(a==0) {
        if(b==0 && c==0) {
            printf("Radacina ecuatiei poate sa fie orice numar real.");
            return -1;
        } else {
            printf("Ecuatia este de gradul 1, drept urmare nu are doua radacini.\nSolutia ecuatiei este: %0.1lf", -c/b);
            return 1;
        }
    }
    else return 2;
}

void get_solutions(double a, double b, double c, double delta, int situation) {
    if(situation == -1 || situation == 1) return;
    else if(situation == 2){
        if (delta >= 0) {
            (delta > 0) ? printf("Radacinile sunt %lf si %lf", ((-b) + sqrt(delta)) / (2 * a), ((-b) + sqrt(delta)) / (2 * a)) : printf("Radacinile sunt egale cu %lf.", ((-b) / (2 * a)));
        } else {
            double aux = sqrt(-delta);
            if (delta < 0)
                printf("Radacinile sunt de tip complex.\nAcestea sunt: %0.2f + %f*i si %0.2f - %f*i", (-b) / (2 * a), aux, (-b) / (2 * a), aux);
        }
    }
}