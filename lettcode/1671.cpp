#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumMountainRemovals(vector<int> &nums) {
    int n = nums.size(), maxsum = 0;
    vector<int> prelist(n, 0), postlist(n, 0);
    stack<int> s;
    for (int count = 0; count < n; count++) {
      while (!s.empty() && nums[s.top()] >= nums[count])
        s.pop();
      s.push(count);
      prelist[count] = s.size();
    }
    stack<int>().swap(s);
    for (int count = n - 1; count >= 0; count--) {
      while (!s.empty() && nums[s.top()] >= nums[count])
        s.pop();
      s.push(count);
      postlist[count] = s.size();
      maxsum = max(maxsum, prelist[count] + postlist[count] - 1);
    }
    return n - maxsum;
  }
};
