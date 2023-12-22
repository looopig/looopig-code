#include <stdio.h>
#include <string.h>

void reversal(char *p, int num) {
  char c;
  for (int left = 0, right = num - 1; left < right; left++, right--) {
    c = *(p + left);
    *(p + left) = *(p + right);
    *(p + right) = c;
  }
}

int main() {
  int length, len = 0;
  char str[80], *p;
  p = str;
  scanf("%[^\n]", str);
  length = strlen(str);
  for (int count = 0; count < length; count++) {
    if (str[count] == ' ') {
      reversal(p, len);
      p = p + len + 1;
      len = 0;
    } else
      len++;
  }
  reversal(p, len);
  reversal(str, length);
  printf("%s", str);
}
