#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <ctype.h>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> r;
        subset(r, nums, 0, std::vector<int>());
        return r;
    }
    void subset(std::vector<std::vector<int>>&r, std::vector<int>& nums, int i, std::vector<int> set) {
        if(i == (int)nums.size())
        {
            r.push_back(set);
            return;
        }
        subset(r, nums, i + 1, set); 
        set.push_back(nums[i]);
        subset(r, nums, i + 1, set); 
    }
};

// To execute C++, please define "int main()"

int main() {
    std::vector<int> nums = {4, 1, 0};
    Solution s;
    std::vector<std::vector<int>> r = s.subsets(nums);
    for(int i = 0; i < (int) r.size(); ++i)
    {
        for(int j = 0; j < (int) r[i].size(); ++j)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
