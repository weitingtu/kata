#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <ctype.h>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = (int) nums.size() - 1;
        while(w <= b)
        {
            if(0 == nums[w]) // red
            {
                int tmp = nums[r];
                nums[r] = nums[w];
                nums[w] = tmp;
                ++r;
                ++w;
            } else if(1 == nums[w]) { // white
                ++w;
            } else { // blue
                int tmp = nums[b];
                nums[b] = nums[w];
                nums[w] = tmp;
                --b;
            }
        }
        
    }
};

// To execute C++, please define "int main()"

int main() {
    std::vector<int> nums = {2, 2, 2};
    Solution s;
    s.sortColors(nums);
    for(int i = 0; i < (int)nums.size(); ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

