#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int len = nums.size(), length = 0;
    vector<int> list(len, 0);
    for (int count = 0; count < len; count++) {
      if (count == 0) {
        list[length++] = nums[count];
      } else {
        int left = 0, right = length - 1, mid;
        while (left <= right) {
          mid = (left + right) / 2;
          if (list[mid] == nums[count]) {
            break;
          } else if (list[mid] < nums[count]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
        if (list[mid] != nums[count]) {
          list[left] = nums[count];
          if (left > length - 1) {
            length++;
          }
        }
      }
    }
    return length;
  }
};
