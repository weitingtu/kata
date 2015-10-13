#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <ctype.h>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> cache;
        std::vector<int> r;
        for(int i = 0; i < (int) nums.size(); ++i)
        {
            if(cache.find(target - nums[i]) != cache.end()) 
            {
                r.push_back(cache[target - nums[i]] + 1);
                r.push_back(i + 1);
                break;
            }
            cache[nums[i]]  = i;
        }
        return r;
    }
};

// To execute C++, please define "int main()"

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    Solution s;
    std::vector<int> r = s.twoSum(nums, 9);
    if((int)r.size() == 2)
        printf("%d %d\n", r[0], r[1]);
    return 0;
}

