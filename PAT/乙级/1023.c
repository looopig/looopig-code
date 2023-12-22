#include <stdio.h>

void print(int num, int elem) {
  for (int count = 0; count < num; count++) {
    printf("%d", elem);
  }
}

int main() {
  int str[10] = {0}, is_ = 0;
  for (int count = 0; count < 10; count++) {
    scanf("%d", &str[count]);
  }
  for (int count = 1; count < 10; count++) {
    if (is_ == 0) {
      if (str[count] != 0) {
        printf("%d", count);
        print(str[0], 0);
        str[count]--;
        print(str[count], count);
        is_ = 1;
      }
    } else {
      if (str[count] != 0) {
        print(str[count], count);
      }
    }
  }
}
