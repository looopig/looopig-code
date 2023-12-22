#include <stdio.h>

int main() {
  int hight, sum, N;
  char c;
  scanf("%d %c", &N, &c);
  sum = 0, hight = 0;
  while (sum + (hight + 1) * 2 - 1 <= (int)((N - 1) / 2 + 1)) {
    sum += (++hight * 2 - 1);
  }
  for (int hight_ = hight; hight_ > 1; hight_--) {
    for (int count_blank = 0; count_blank < hight - hight_; count_blank++) {
      putchar(' ');
    }
    for (int count_star = 0; count_star < (hight_ * 2 - 1); count_star++) {
      putchar(c);
    }
    printf("\n");
  }
  for (int hight_ = 1; hight_ <= hight; hight_++) {
    for (int count_blank = 0; count_blank < hight - hight_; count_blank++) {
      putchar(c);
    }
    for (int count_star = 0; count_star < (hight_ * 2 - 1); count_star++) {
      putchar('*');
    }
    printf("\n");
  }
  printf("%d", N - ((sum - 1) * 2 + 1));
}
