#include <stdio.h>

int is_(int num) {
  if (num == 2 || num == 3) {
    return 1;
  }
  for (int count = 2; count * count <= num; count++) {
    if (num % count == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int M, N, num = 2;
  int count_list = 0, count_num = 0;
  scanf("%d %d", &M, &N);
  while (count_num < N) {
    if (is_(num)) {
      count_num++;
      if (count_num >= M) {
        printf("%d", num);
        count_list++;
        if (count_list != 10) {
          if (count_num < N) {
            printf(" ");
          }
        } else {
          printf("\n");
          count_list = 0;
        }
      }
    }
    num++;
  }
}
