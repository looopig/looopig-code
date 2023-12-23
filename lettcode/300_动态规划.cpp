#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size(), maxlen = 0;
    vector<int> list(n, 0);
    for (int count = 0; count < n; count++) {
      if (count == 0) {
        list[count] = 1;
      } else {
        int maxsum = 1, sum;
        for (int i = 0; i < count; i++) {
          if (nums[i] < nums[count]) {
            sum = list[i] + 1;
            if (maxsum < sum)
              maxsum = sum;
          }
        }
        list[count] = maxsum;
      }
      maxlen = max(maxlen, list[count]);
    }
    return maxlen;
  }
};
