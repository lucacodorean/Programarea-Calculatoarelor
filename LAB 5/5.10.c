#include <stdio.h>
#include <stdlib.h>

int get_bills(int sum);
int reduce_sum(int init_sum, int reduce_by);

int main(void) {
  printf("Introduceti suma pe are doriti sa o verificati. n = ");
  int sum; scanf("%d", &sum);
  printf("Pentru a acoperi %d lei, ai nevoie de %d bacnote.\n", sum, get_bills(sum));

  return 0;
}

int reduce_sum(int init_sum, int reduce_by) {
  int sum = init_sum;
  while(sum>=reduce_by) {
    sum-=reduce_by;
  }

  return sum;
}

int get_bills(int sum) {
  int result = 0;
  while(sum>0) {
    if(sum>=500) { sum=reduce_sum(sum, 500); result++; }
    else {
      if(sum>=200) { sum=reduce_sum(sum, 200); result++; }
      if (sum>=100) { sum=reduce_sum(sum, 100); result++; }
      if (sum>=50) { sum=reduce_sum(sum, 50); result++; }
      if (sum>=20) { sum=reduce_sum(sum, 20); result++; }
      if (sum>=10) { sum=reduce_sum(sum, 10); result++; }
      if (sum>=5) { sum=reduce_sum(sum, 5); result++; }
      if (sum>=1) { sum=reduce_sum(sum, 1); result++; }
    }
  }

  return result;
}
