#include <stdio.h>

int main() {
  int p_1 = 0, p_2 = 0, p = 0, asc_p = 0, asc[300] = {0};
  char str_1[85], str_2[85], str[85];
  scanf("%s %s", str_1, str_2);
  while (str_1[p_1] != '\0') {
    if (str_1[p_1] == str_2[p_2]) {
      p_1++, p_2++;
    } else {
      if (str_1[p_1] >= 'a' && str_1[p_1] <= 'z') {
        str_1[p_1] = (char)((int)str_1[p_1] - (int)('a' - 'A'));
      }
      if (asc[(int)str_1[p_1]] == 0) {
        str[p++] = str_1[p_1];
        asc[(int)str_1[p_1]] = 1;
      }
      p_1++;
    }
  }
  str[p] = '\0';
  printf("%s", str);
}
