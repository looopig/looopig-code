#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    int n = maxHeights.size();
    long long maxsum = 0;
    vector<long long> prelist(n, 0), postlist(n, 0);
    stack<int> s1, s2;
    for (int count = 0; count < n; count++) {
      while (!s1.empty() && maxHeights[s1.top()] > maxHeights[count])
        s1.pop();
      if (s1.empty()) {
        prelist[count] = (long long)(count + 1) * maxHeights[count];
        s1.push(count);
      } else {
        prelist[count] = prelist[s1.top()] +
                         (long long)(count - s1.top()) * maxHeights[count];
        s1.push(count);
      }
    }
    for (int count = n - 1; count >= 0; count--) {
      while (!s2.empty() && maxHeights[s2.top()] > maxHeights[count])
        s2.pop();
      if (s2.empty()) {
        prelist[count] = (long long)(n - count) * maxHeights[count];
        s2.push(count);
      } else {
        prelist[count] = prelist[s2.top()] +
                         (long long)(s2.top() - count) * maxHeights[count];
        s2.push(count);
      }
      maxsum =
          max(maxsum, prelist[count] + postlist[count] - maxHeights[count]);
    }

    return maxsum;
  }
};
