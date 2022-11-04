//
// Created by Luca Codorean on 10/18/2022.//

#include <stdio.h>
#include <math.h>

#define PI 3.141529
#define multiplication_constant 180/PI

const float convert_to_degree(double angle) { return angle*multiplication_constant; }
const double get_minutes(float degree) {
    double minutes = modf(degree, &minutes);
    return minutes*60;
}
const double get_seconds(double minutes) {
    double seconds = modf(minutes, &seconds);
    return seconds*60;
}

int main() {
    double x;
    scanf("%lf", &x);
    float degree_value = convert_to_degree(x);
    double minutes_value = get_minutes(degree_value);
    double seconds_value = get_seconds(minutes_value);
    printf("Valorea %.2lf radiani corespunde unui unghi de %d grade, %d minute si %d secunde.",x, (int)degree_value, (int)minutes_value, (int)seconds_value);
    return 0;
}