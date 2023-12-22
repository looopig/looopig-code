#include <iostream>
#include <string>

int main() {
  int N, count;
  std::string passwd_true, passwd;
  std::cin >> passwd_true >> N;
  std::cin.get();
  for (count = 0; count < N; count++) {
    std::getline(std::cin, passwd);
    if (passwd == "#") {
      break;
    } else if (passwd_true == passwd) {
      std::cout << "Welcome in" << std::endl;
      break;
    } else {
      std::cout << "Wrong password: " << passwd << std::endl;
    }
  }
  if (count == N) {
    std::cout << "Account locked";
  }
}
