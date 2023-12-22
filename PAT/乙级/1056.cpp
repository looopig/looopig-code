#include <iostream>

int main() {
  int N, num, sum = 0;
  std::cin >> N;
  for (int count = 0; count < N; count++) {
    std::cin >> num;
    sum += num;
  }
  std::cout << 11 * (N - 1) * sum << std::endl;
}
