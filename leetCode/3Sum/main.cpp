#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> r;
        
        for(int i = 0; i < (int)nums.size(); ++i)
        {
            int start = i + 1;
            int end   = (int) nums.size() - 1;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(0 == sum)
                {
                    std::vector<int> s(3);
                    s[0] = nums[i];
                    s[1] = nums[start];
                    s[2] = nums[end];
                    r.push_back(s);
                        
                    ++start;
                    --end;
                    while((start < end) && (nums[start - 1] == nums[start]))
                        ++start;
                    while((start < end) && (nums[end + 1] == nums[end])) 
                        --end;
                } else if(sum  < 0) {
                    ++start;
                    while((start < end) && (nums[start - 1] == nums[start]))
                        ++start;
                } else {
                    --end;
                    while((start < end) && (nums[end + 1] == nums[end]))
                        --end;
                }
            }
            while((i + 1 < (int)nums.size()) && (nums[i + 1] == nums[i]))
                ++i;
        }
        
        return r;
    }
};


// To execute C++, please define "int main()"

int main() {
    std::vector<int> nums =  {-1, 0, 1, 2, -1, -4};
    Solution s;
    std::vector<std::vector<int>> r = s.threeSum(nums);
    for(int i = 0; i< (int)r.size(); ++i)
    {
        for(int j = 0; j < (int)r[i].size(); ++j)
        {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
  return 0;
}

