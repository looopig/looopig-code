#include <vector>
using namespace std;

class Solution {
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    int x, y;
    if ((tomatoSlices - 2 * cheeseSlices) % 2 == 0) {
      x = (tomatoSlices - 2 * cheeseSlices) / 2;
      y = cheeseSlices - x;
    } else {
      return vector<int>();
    }
    if (x >= 0 && y >= 0)
      return vector<int>({x, y});
    else
      return vector<int>();
  }
};
