#include <stdio.h>

int main() {
  int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  char str[20];
  int N, Z, error_num = 0;
  scanf("%d", &N);
  for (int count = 0; count < N; count++) {
    scanf("%s", str);
    Z = 0;
    for (int i = 0; i < 17; i++) {
      Z += (int)(str[i] - '0') * weight[i];
    }
    Z %= 11;
    if (M[Z] != str[17]) {
      printf("%s\n", str);
      error_num++;
    }
  }
  if (error_num == 0) {
    printf("All passed");
  }
}
