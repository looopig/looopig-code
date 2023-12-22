/*
 * 有两个非常坑得点，一个就是起初给的值不一定是四位数，则需要格式化一下
 * 还有一个就是给的值可能是 6174 在我代码中不能进入循环输出，若是 6174 也要
 * 输出一次才行
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_up(const void *a, const void *b) { return *(char *)a - *(char *)b; }
int cmp_down(const void *a, const void *b) { return *(char *)b - *(char *)a; }

int main() {
  char N[5];
  int N1, N2;
  scanf("%d", &N1);
  sprintf(N, "%04d", N1);
  while (strcmp(N, "6174") != 0) {
    qsort(N, 4, sizeof(char), cmp_down);
    sscanf(N, "%d", &N1);
    qsort(N, 4, sizeof(char), cmp_up);
    sscanf(N, "%d", &N2);
    if (N1 == N2) {
      printf("%04d - %04d = 0000", N1, N2);
      break;
    } else {
      printf("%04d - %04d = %04d\n", N1, N2, N1 - N2);
      sprintf(N, "%04d", N1 - N2);
    }
  }
}
