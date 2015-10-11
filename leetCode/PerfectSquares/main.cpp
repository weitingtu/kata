#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            int j = 1;
            while((i - j*j) >= 0)
            {
                dp[i] = std::min(dp[i], dp[i - j*j] + 1);
                ++j;
            }
        }
        return dp[n];
    }
};

// To execute C++, please define "int main()"

int main() {
    Solution s;
    assert(s.numSquares(100) == 1);
 
    return 0;
}
