#include <stdio.h>

int main() {
  int A, B, D, sum, c[35], p = 0;
  scanf("%d %d %d", &A, &B, &D);
  sum = A + B;
  if (sum == 0) {
    printf("0");
  }
  while (sum != 0) {
    c[p++] = sum % D;
    sum = (int)(sum / D);
  }
  for (int count = p - 1; count >= 0; count--) {
    printf("%d", c[count]);
  }
}
