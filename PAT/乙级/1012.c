#include <stdio.h>

typedef struct AS {
  int _is;
  int date, num;
} AS;

int main() {
  AS A[5] = {0};
  int num_case, N;
  int is_1 = 0;
  scanf("%d", &num_case);
  for (int count = 0; count < num_case; count++) {
    scanf("%d", &N);
    switch (N % 5) {
    case 0:
      if (N % 2 == 0) {
        A[0]._is = 1;
        A[0].num++;
        A[0].date += N;
      }
      break;
    case 1:
      A[1]._is = 1;
      A[1].num++;
      if (is_1 == 0) {
        A[1].date += N;
        is_1 = 1;
      } else {
        A[1].date -= N;
        is_1 = 0;
      }
      break;
    case 2:
      A[2]._is = 1;
      A[2].num++;
      A[2].date++;
      break;
    case 3:
      A[3]._is = 1;
      A[3].num++;
      A[3].date += N;
      break;
    case 4:
      A[4]._is = 1;
      A[4].num++;
      if (N > A[4].date) {
        A[4].date = N;
      }
      break;
    }
  }
  for (int count = 0; count < 5; count++) {
    if (A[count]._is == 0) {
      printf("N");
    } else {
      if (count == 3) {
        printf("%.1f", (float)A[count].date / A[count].num);
      } else {
        printf("%d", A[count].date);
      }
    }
    if (count != 4)
      printf(" ");
  }
}
