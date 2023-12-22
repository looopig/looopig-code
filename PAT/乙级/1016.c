#include <stdio.h>

int compute_p(int num, int num_D) {
  int sum = 0;
  for (int count = 0; count < num_D; count++) {
    sum = sum * 10 + num;
  }
  return sum;
}

int main() {
  char str[15], c;
  int p, num_D, sum = 0;
  for (int count = 0; count < 2; count++) {
    scanf("%s %c", str, &c);
    num_D = 0, p = 0;
    while (str[p] != '\0') {
      if (str[p] == c) {
        num_D++;
      }
      p++;
    }
    sum = sum + compute_p((int)(c - '0'), num_D);
  }
  printf("%d", sum);
}
