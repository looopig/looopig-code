#include <stdio.h>

int main() {
  int num_case;
  long A, B, C;
  scanf("%d", &num_case);
  for (int count = 0; count < num_case; count++) {
    scanf("%ld %ld %ld", &A, &B, &C);
    if (A + B > C) {
      printf("Case #%d: true\n", count + 1);
    } else {
      printf("Case #%d: false\n", count + 1);
    }
  }
}
