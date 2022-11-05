#include <stdio.h>
#include <stdlib.h>

void time(int day, int month, int year);

int main(void) {
  int day, month, year;
  scanf("%d %d %d", &day, &month, &year);
  time(day,month,year);
  return 0;
}

void time(int day, int month, int year) {

  int total_days = day;
  int months[] = {0, 31, 28 + (year%400 == 0 || year%4 == 0 && year%100 == 0 ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for(int i = 1; i<l; i++) total_days+=months[i];

  printf("Au trecut %d zile si au mai ramas %d zile, din anul %d.\n", total_days, (year%400 == 0 || year%4 == 0 && year%100 == 366 ? 365 : 0)-total_days, year);
}
