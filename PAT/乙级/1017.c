#include <stdio.h>

int main() {
  char A[1005], Q[1005];
  int B, R, p1, p2;
  scanf("%s %d", A, &B);
  p1 = p2 = R = 0;
  while (A[p1] != '\0') {
    R = R * 10 + (A[p1] - '0');
    if (p1 == 0) {
      if ((int)(R / B) != 0) {
        Q[p2] = (int)(R / B) + '0';
        R %= B;
        p2++;
      }
    } else {
      if ((int)(R / B) != 0) {
        Q[p2] = (int)(R / B) + '0';
        R %= B;
        p2++;
      } else {
        Q[p2] = '0';
        p2++;
      }
    }
    p1++;
  }
  if (p2 == 0) {
    Q[p2] = '0';
    p2++;
  }
  Q[p2] = '\0';
  printf("%s %d", Q, R);
}
