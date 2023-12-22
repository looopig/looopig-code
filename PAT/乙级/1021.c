#include <stdio.h>

int main() {
  char str[1005];
  int list[10] = {0};
  scanf("%s", str);
  for (int count = 0; str[count] != '\0'; count++) {
    list[str[count] - '0']++;
  }
  for (int count = 0; count < 10; count++) {
    if (list[count] != 0) {
      printf("%d:%d\n", count, list[count]);
    }
  }
}
