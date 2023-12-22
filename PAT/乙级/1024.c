#include <stdio.h>
#include <string.h>

int main() {
  char str[10000];
  int str_length, zero_num;
  scanf("%c%c.%[^E]E%d", &str[0], &str[1], str + 2, &zero_num);
  zero_num++;
  if (str[0] == '-') {
    printf("%c", str[0]);
  }
  if (zero_num <= 0) {
    printf("0.");
    for (int count = zero_num; count < 0; count++) {
      printf("0");
    }
    printf("%s", str + 1);
  } else if ((strlen(str) - 1) > zero_num) {
    for (int count = 1; count <= zero_num; count++) {
      printf("%c", str[count]);
    }
    printf(".");
    printf("%s", str + zero_num + 1);
  } else {
    printf("%s", str + 1);
    for (int count = 0; count < zero_num - strlen(str) + 1; count++) {
      printf("0");
    }
  }
}
