#include <stdio.h>

int main() {
  int asc[260] = {0};
  char c;
  c = getchar();
  while (c != '\n') {
    asc[(int)c]++;
    c = getchar();
  }
  int is_null = 0;
  while (!is_null) {
    is_null = 1;
    if (asc[(int)'P']) {
      putchar('P');
      asc[(int)'P']--;
      is_null = 0;
    }
    if (asc[(int)'A']) {
      putchar('A');
      asc[(int)'A']--;
      is_null = 0;
    }
    if (asc[(int)'T']) {
      putchar('T');
      asc[(int)'T']--;
      is_null = 0;
    }
    if (asc[(int)'e']) {
      putchar('e');
      asc[(int)'e']--;
      is_null = 0;
    }
    if (asc[(int)'s']) {
      putchar('s');
      asc[(int)'s']--;
      is_null = 0;
    }
    if (asc[(int)'t']) {
      putchar('t');
      asc[(int)'t']--;
      is_null = 0;
    }
  }
}
