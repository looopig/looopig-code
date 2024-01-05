#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int> &heights) {
    int n = heights.size();
    stack<int> _stack;
    vector<int> list(n, 0);
    _stack.push(0);
    for (int count = 1; count < n; count++) {
      while (!_stack.empty()) {
        list[_stack.top()]++;
        if (heights[count] >= heights[_stack.top()]) {
          _stack.pop();
        } else {
          break;
        }
      }
      _stack.push(count);
    }
    return list;
  }
};
