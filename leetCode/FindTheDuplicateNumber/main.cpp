#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        if((int) nums.size() <= 1)
            return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(fast != slow)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

// To execute C++, please define "int main()"

int main() {
    std::vector<int> nums = {1, 1};
    Solution s;
    s.findDuplicate(nums);
    assert(s.findDuplicate(nums) == 1);
 
    return 0;
}

