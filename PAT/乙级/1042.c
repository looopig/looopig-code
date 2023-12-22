#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)b; }

int main() {
  int asc[260] = {0};
  char c;
  c = getchar();
  while (c != '\n') {
    if (c <= 'z' && c >= 'a') {
      asc[(int)c]++;
    } else if (c >= 'A' && c <= 'Z') {
      asc[(int)(c + ('a' - 'A'))]++;
    }
    c = getchar();
  }
  int max = 'a';
  for (int count = 'a'; count <= 'z'; count++) {
    if (asc[count] > asc[max]) {
      max = count;
    }
  }
  printf("%c %d", (char)max, asc[max]);
}
