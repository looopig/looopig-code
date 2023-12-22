#include <stdio.h>

int main() {
  int N;
  char c;
  scanf("%d %c", &N, &c);
  for (int hang = 0; hang < (int)((N / 2.0) + 0.5); hang++) {
    if (hang == 0 || hang + 1 == (int)((N / 2.0) + 0.5)) {
      for (int count = 0; count < N; count++) {
        putchar(c);
      }
    } else {
      putchar(c);
      for (int count = 0; count < N - 2; count++) {
        putchar(' ');
      }
      putchar(c);
    }
    putchar('\n');
  }
}
