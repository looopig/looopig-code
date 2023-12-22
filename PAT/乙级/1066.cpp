/*
 * 使用 C++ 语言的一定要注意的是 cin 的速度要远低于 scanf 的速度
 */

#include <cstdio>
#include <iostream>

int main() {
  int M, N, A, B, C, D;
  std::cin >> M >> N >> A >> B >> C;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &D);
      if (D >= A && D <= B) {
        printf("%03d", C);
      } else {
        printf("%03d", D);
      }
      if (j + 1 == N) {
        std::cout << '\n';
      } else {
        std::cout << ' ';
      }
    }
  }
}
