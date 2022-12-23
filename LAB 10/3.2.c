// Created by Luca Codorean on 12/14/2022.

#include <stdio.h>
#include <math.h>

enum Weekdays {monday, tuesday, wednesday, thusday, friday, saturday, sunday};

typedef struct {
    int day, month, year;
    enum Weekdays birth_week_day;
} DATE;

DATE init_birthday(int, int, int);
void set_birthday_week_day(DATE*, int);
void print_birthday(DATE);
char* weekday_string(DATE);
int day_of_week_of_birthday(DATE);
void get_day(DATE, int*);
void get_month(DATE, int*);
void get_year(DATE, int*);

int main(void) {
    DATE birthday = init_birthday(11,07,2003);
    set_birthday_week_day(&birthday, 2);
    print_birthday(birthday);
    return 0;
}

DATE init_birthday(int dd, int mm, int yyyy) {
    DATE result;
    result.day = dd;
    result.month = mm;
    result.year = yyyy;
    return result;
}
void set_birthday_week_day(DATE* parameter, int value) {parameter->birth_week_day = value;}
char* weekday_string(DATE parameter) {
    switch (day_of_week_of_birthday(parameter)) {
        case 0: return "Monday";
        case 1: return "Tuesday";
        case 2: return "Wednesday";
        case 3: return "Thusday";
        case 4: return "Friday";
        case 5: return "Saturday";
        default: return "Sunday";
    }
}
void print_birthday(DATE parameter) { printf("%d, %s, %d/%d/%d", day_of_week_of_birthday(parameter), weekday_string(parameter), parameter.month, parameter.day, parameter.year );}

void get_day(DATE parameter, int* day)      { *day = parameter.day; }
void get_month(DATE parameter, int* month)  { *month = parameter.month; }
void get_year(DATE parameter, int* year)    { *year = parameter.year; }

int day_of_week_of_birthday(DATE parameter) {
    int day, month, year;
    get_day(parameter, &day);
    get_month(parameter, &month);
    get_year(parameter, &year);
    return (int)(day + floor(2.6f*month - 0.2f) - 2*(year/100) + year + floor(year/4) + floor(year/400))%7;
}
