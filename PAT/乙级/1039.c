#include <stdio.h>
#include <stdlib.h>

int main() {
  int asc[260] = {0}, num_shao = 0, num_duo = 0;
  char c;
  c = getchar();
  while (c != '\n') {
    asc[(int)c]++;
    c = getchar();
  }
  c = getchar();
  while (c != '\n') {
    asc[(int)c]--;
    c = getchar();
  }
  for (int count = 0; count < 260; count++) {
    if (asc[count] < 0) {
      num_shao += asc[count];
    } else {
      num_duo += asc[count];
    }
  }
  if (num_shao == 0) {
    printf("Yes %d", num_duo);
  } else {
    printf("No %d", abs(num_shao));
  }
}
