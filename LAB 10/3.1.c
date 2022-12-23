#include <stdio.h>

typedef struct{
    unsigned short day, month, year;
} DATE;

void scanf_date(DATE*);
void printf_date(DATE);
const unsigned short convert_to_days(DATE);
const unsigned short month_to_days(DATE);

int main(void) {
    DATE today;
    scanf_date(&today);

    DATE last_date_of_the_year;
    last_date_of_the_year.day = 31;
    last_date_of_the_year.month = 12;
    puts("Insert the current year:"); scanf("%hu", &last_date_of_the_year.year);

    unsigned int result = convert_to_days(last_date_of_the_year)-convert_to_days(today);
    printf("There are %d day%s left in this year.", result, result >1 ? "s" : "");
    return 0;
}

void scanf_date(DATE* parameter) {
    puts("Insert the current date (mm/dd/yyyy):");
    scanf("%hu/%hu/%hu", &parameter->month, &parameter->day, &parameter->year);
}

void printf_date(DATE parameter) {
    printf("%hu/%hu/%hu", parameter.month, parameter.day, parameter.year);
}

const unsigned short month_to_days(DATE parameter) {
    switch (parameter.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 2:
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default: return ((parameter.year % 4 == 0 && parameter.year % 100 != 0) || parameter.year%400==0) ? 29 : 28;
    }
}

const unsigned short convert_to_days(DATE parameter) {
    unsigned short result = parameter.day;
    for(int i = 1; i<parameter.month; i++) {
            result+= month_to_days(parameter);
    }
    return result;
}