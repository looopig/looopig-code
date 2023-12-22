#include <stdio.h>

int K, num[110] = {0};

int main() {
  int n;
  scanf("%d", &K);
  for (int count = 0; count < K; count++) {
    scanf("%d", &n);
    if (num[n] != 2) {
      num[n] = 1;
    }
    while (n != 1) {
      if (n % 2 == 1) {
        n = 3 * n + 1;
      }
      n = n / 2;
      if (n <= 100 && n > 1) {
        num[n] = 2;
      }
    }
  }
  int y_n = 0;
  for (int count = 109; count > 0; count--) {
    if (num[count] == 1) {
      if (y_n == 0) {
        printf("%d", count);
        y_n = 1;
      } else {
        printf(" %d", count);
      }
    }
  }
}
