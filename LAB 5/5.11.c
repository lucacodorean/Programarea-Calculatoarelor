#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOUND      1
#define NOT_FOUND -1

/// memcmp(pointer, pointer, size) => Compara primii biti a primului pointer cu primii size biti ai celui de al doilea pointer.
///    return 0  -> pointerii au valoare egala;
//     return <0 -> pointer_1 < pointer_2
//     return >0 -> pointer_1 > pointer_2

int strstr_stupid(const char* bigger_string, const char* lower_string);

int main(void) {
  char longer_text[256]; scanf("%[^\n]", longer_text);
  fflush(stdin);
  char shorter_text[256]; scanf("\n%[^\n]", shorter_text);


  printf("Sirul %s%s se gaseste in sirul %s.\n", shorter_text, strstr_stupid(longer_text, shorter_text)!=NOT_FOUND ? "" : " nu", longer_text);
  return 0;
}

int strstr_stupid(const char* bigger_string, const char* lower_string) {

 unsigned int size_of_bigger = strlen(bigger_string);

 int start = 0;
 while(*bigger_string) {
   if(!memcmp(bigger_string, lower_string, size_of_bigger)) return start;
   start++;
   *bigger_string++;
 }

 return NOT_FOUND;
}
