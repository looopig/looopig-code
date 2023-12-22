/*
* 这题最困难的是若是 M > N 则应该怎么调转数组
* 因为此处调转是可以看作一个循环数组，所以可以更具取余的方式规划 M 的大小
*/

#include <stdio.h>

void reversal(int *p, int num){
  if (num == 0) return;
  int temp, left = 0, right = num - 1;
  for (; left < right; left++, right--) {
    temp = *(p + left);
    *(p + left) = *(p + right);
    *(p + right) = temp;
  }
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  M = M % N;    // 此处可以将 M 直接规划成小于 N 的一个数
  int A[N];
  for (int count = 0; count < N; count++) {
    scanf("%d", &A[count]);
  }
  reversal(A, N - M);
  reversal(A + (N - M), M);
  reversal(A, N);
  for (int count = 0; count < N; count++) {
    printf("%d", A[count]);
    if (count != N - 1) {
      printf(" ");
    }
  }
}
