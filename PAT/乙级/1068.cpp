#include <iostream>
#include <vector>

int mcin() {
  int M, N, TOL, num;
  std::cin >> M >> N >> TOL;
  std::vector<std::vector<int>> array(M, std::vector<int>(N));
  std::vector<std::vector<int>>::iterator row;
  std::vector<int>::iterator index;
  for (row = array.begin(); row != array.end(); row++) {
    for (index = row->begin(); index != row->end(); index++) {
      std::cin >> *(index);
    }
  }
  return 0;
}
