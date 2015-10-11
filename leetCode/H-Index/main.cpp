#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int l = 0;
        int r = (int) citations.size() - 1;
        int mid;
        int i = 0;
        while(l <= r)
        {
            mid = l + ((r - l) >> 1);
            if(citations[mid] >= ((int) citations.size() - mid))
            {
                r = mid - 1;
                i = (int) citations.size() - mid;
            } else {
                l = mid + 1;
            }
        }
        
        return i;
    }
};

// To execute C++, please define "int main()"

int main() {
    std::vector<int> citations = {0, 3, 1, 5, 6};
    Solution s;
//    assert(s.findDuplicate(nums) == 3);
    printf("%d\n", s.hIndex(citations));
 
    return 0;
}
