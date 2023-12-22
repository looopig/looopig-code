#include <stdio.h>

int is_prime_number(int num) {
  for (int count = 2; count * count <= num; count++) {
    if (num % count == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int nums, is_num = 0;
  int p = 3, pre = 2;
  scanf("%d", &nums);
  for (int count = 4; count <= nums; count++) {
    if (is_prime_number(count)) {
      pre = p;
      p = count;
      if ((p - pre) == 2) {
        is_num++;
      }
    }
  }
  printf("%d", is_num);
}
