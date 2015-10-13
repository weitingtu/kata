#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <ctype.h>

class Solution {
public:
    int mySqrt(int x) {
/*        int l = 0;
        int r = x;
        int mid;
        while(l <= r)
        {
            mid = l + ((r - l) >> 1);
            if((mid*mid <= x) && (((mid + 1)*(mid + 1)) > x))
                break;
            else if(mid*mid < x)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return mid;*/
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};

// To execute C++, please define "int main()"

int main() {
    Solution s;
    printf("%d\n", s.mySqrt(0));
    printf("%d\n", s.mySqrt(1));
    printf("%d\n", s.mySqrt(2));
    printf("%d\n", s.mySqrt(3));
    printf("%d\n", s.mySqrt(4));
    printf("%d\n", s.mySqrt(5));
    printf("%d\n", s.mySqrt(6));
    printf("%d\n", s.mySqrt(7));
    printf("%d\n", s.mySqrt(8));
    printf("%d\n", s.mySqrt(9));
    return 0;
}

