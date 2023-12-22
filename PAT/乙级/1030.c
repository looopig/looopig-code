#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(long *)a - *(long *)b; }

int main() {
  int N, left = 0, right = 0, num = 0;
  long p, list[100000];
  scanf("%d %ld", &N, &p);
  for (int count = 0; count < N; count++) {
    scanf("%ld", &list[count]);
  }
  qsort(list, N, sizeof(long), cmp);
  while (left != N && right != N) {
    if (list[left] * p < list[right]) {
      left++;
      if (N - left <= num) {
        break;
      } else {
        right = left + num;
      }
    } else {
      right++;
      num++;
    }
  }
  printf("%d", num);
}
