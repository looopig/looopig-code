#include <stdio.h>

int main() {
  int asc[300] = {0}, p = 0, num = 0;
  char str_error[100005], str_input[100005];
  scanf("%[^\n]", str_error);
  scanf("%s", str_input);
  while (str_error[p] != '\0') {
    if (str_error[p] >= 'A' && str_error[p] <= 'Z') {
      asc[(int)str_error[p]] = 1;
      asc[(int)(str_error[p] + ('a' - 'A'))] = 1;
    } else if (str_error[p] == '+') {
      for (int count = 'A'; count <= 'Z'; count++) {
        asc[count] = 1;
      }
    } else {
      asc[(int)str_error[p]] = 1;
    }
    p++;
  }
  p = 0;
  while (str_input[p] != '\0') {
    if (asc[(int)str_input[p]] != 1) {
      putchar(str_input[p]);
    }
    p++, num++;
  }
  if (num == 0) {
    printf(" ");
  }
}
