#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

typedef struct {
  std::string name;
  int height;
} Student;

bool cmp(Student a, Student b) {
  if (a.height == b.height) {
    return a.name < b.name;
  } else {
    return a.height > b.height;
  }
}

int main() {
  int N, K, len_K, len_1, _left, left, mid, _right, right;
  std::cin >> N >> K;
  len_K = N / K, len_1 = N - len_K * (K - 1);
  std::vector<Student> list(N);
  for (std::vector<Student>::iterator IT = list.begin(); IT != list.end();
       IT++) {
    std::cin >> IT->name >> IT->height;
  }
  std::sort(list.begin(), list.end(), cmp);
  std::vector<Student>::iterator IT = list.begin();
  std::vector<Student> list_save(N);
  mid = len_1 / 2;
  _left = 0, _right = len_1 - 1;
  for (int count = 1; count <= K; count++) {
    list_save[mid] = *(IT++);
    left = mid - 1, right = mid + 1;
    while (true) {
      if (left >= _left) {
        list_save[left--] = *(IT++);
      }
      if (right <= _right) {
        list_save[right++] = *(IT++);
      }
      if (left < _left) {
        break;
      }
    }
    mid += len_K;
    _left = _right + 1;
    _right = _left + len_K - 1;
    for (int count = left + 1; count < right; count++) {
      std::cout << list_save[count].name;
      if (count + 1 == right) {
        std::cout << std::endl;
      } else {
        std::cout << ' ';
      }
    }
  }
}
