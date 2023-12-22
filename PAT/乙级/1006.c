#include <stdio.h>

int main() {
  int num, str[3] = {0};
  scanf("%d", &num);
  for (int count = 2; count >= 0; count--) {
    str[count] = num % 10;
    num = num / 10;
  }
  for (int count = 0; count < str[0]; count++) {
    printf("B");
  }
  for (int count = 0; count < str[1]; count++) {
    printf("S");
  }
  for (int count = 1; count <= str[2]; count++) {
    printf("%d", count);
  }
}
