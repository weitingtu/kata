#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {(void) version; return true;}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int mid;
        while(l < r)
        {
            mid = l + ((r - l) >> 1);
            isBadVersion(mid) ? r = mid : l = mid + 1;
        }
        return r;
    }
};

// To execute C++, please define "int main()"

int main() {
    Solution s;
//    assert(s.findDuplicate(nums) == 2);
    printf("%d\n", s.firstBadVersion(10));
 
    return 0;
}
