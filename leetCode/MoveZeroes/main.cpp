#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int size = (int) nums.size();
        int n = 0;
        int i = 0;
        while(i < size)
        {
            if(nums[i] != 0)
            {
                std::swap(nums[i], nums[n]);
                ++n;
            } 
            ++i;
        }
    }
};

// To execute C++, please define "int main()"

int main() {
    std::vector<int> nums = {0 , 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums);
    for(int i = 0; i <(int) nums.size();++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
 
    return 0;
}

