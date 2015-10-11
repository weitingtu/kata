#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution
{
public:
    int missingNumber( std::vector<int>& nums )
    {
        int sum = ( 0 + ( int )nums.size() ) * ( ( int )nums.size() + 1 ) / 2;
        for ( int i = 0; i < ( int )nums.size(); ++i )
        {
            sum -= nums[i];
        }
        return sum;
    }
};

// To execute C++, please define "int main()"

int main()
{
    std::vector<int> nums = {0, 1, 3};
    Solution s;
    assert( s.missingNumber( nums ) == 2 );

    return 0;
}
