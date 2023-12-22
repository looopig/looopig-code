#include <stdio.h>

typedef struct Money {
  int galleon, sickle, knut;
  int num;
} Money;

int main() {
  Money P, A, C;
  scanf("%d.%d.%d %d.%d.%d", &P.galleon, &P.sickle, &P.knut, &A.galleon,
        &A.sickle, &A.knut);
  P.num = P.galleon * 17 * 29 + P.sickle * 29 + P.knut;
  A.num = A.galleon * 17 * 29 + A.sickle * 29 + A.knut;
  C.num = A.num - P.num;
  if (C.num < 0) {
    putchar('-');
    C.num = -C.num;
  }
  C.knut = C.num % 29;
  C.sickle = (int)(C.num / 29);
  C.galleon = (int)(C.sickle / 17);
  C.sickle = C.sickle % 17;
  printf("%d.%d.%d", C.galleon, C.sickle, C.knut);
}
