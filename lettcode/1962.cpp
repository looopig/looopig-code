#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> q(piles.begin(), piles.end());
    int mid;
    for (int count = 0; count < k; count++) {
      mid = (q.top() + 1) / 2;
      q.pop();
      q.push(mid);
    }
    int length = 0;
    while (!q.empty()) {
      length += q.top();
      q.pop();
    }
    return length;
  }
};
