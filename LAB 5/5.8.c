#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int convert_letter(char letter) {

  int result = 0;
  switch(letter) {
    case 'V' :
      result = 5;
      break;
    case 'X' :
      result = 10;
      break;
    case 'L' :
      result = 50;
      break;
    case 'C' :
      result = 100;
      break;
    case 'D' :
      result = 500;
      break;
    case 'M' :
      result = 1000;
      break;
    default:
      result = 1;
      break;
  }

  return result;
}


int convert_year(char year[30]) {

  int result = 0;

  for(int i = 0; i<strlen(year); i++) {
      int  first_value = convert_letter(year[i]);
      int second_value = convert_letter(year[i+1]);

      result += (i+1 < strlen(year) ? (first_value >= second_value ? first_value : second_value - first_value) : second_value);
  }

  return result;
}


int main(void) {
  char number[30];
  int n = 0;
  puts("Introduceti un nuumar de maxim 30 de litere.");
  scanf("%[^\n]", number);
  printf("%d\n", convert_year(number));
  return 0;
}
