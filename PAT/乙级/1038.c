#include <stdio.h>

int main() {
  int nums[101] = {0};
  int N, K, num;
  scanf("%d", &N);
  for (int count = 0; count < N; count++) {
    scanf("%d", &num);
    nums[num]++;
  }
  scanf("%d", &K);
  for (int count = 0; count < K; count++) {
    scanf("%d", &num);
    if (count == 0) {
      printf("%d", nums[num]);
    } else {
      printf(" %d", nums[num]);
    }
  }
}
