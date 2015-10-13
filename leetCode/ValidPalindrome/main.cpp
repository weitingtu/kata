#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_set>
#include <ctype.h>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0;
        int j = (int) s.size() - 1;
        while(i < j)
        {
            if(isalnum(s[i]) && isalnum(s[j]) && (tolower(s[i++]) != tolower(s[j--])))
            {
                return false;
            }
            while(!isalnum(s[i]) && (i < (int) s.size()))
            {
                ++i;
            }
            while(!isalnum(s[j]) && (j >= 0))
            {
                --j;
            }
        }
        return true;
    }
};

// To execute C++, please define "int main()"

int main() {
    Solution s;
    printf("%s\n", s.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false");
    printf("%s\n", s.isPalindrome("race a car") ? "true" : "false");
    printf("%s\n", s.isPalindrome("madam") ? "true" : "false");
    printf("%s\n", s.isPalindrome("") ? "true" : "false");
    printf("%s\n", s.isPalindrome(" ") ? "true" : "false");
    printf("%s\n", s.isPalindrome("!!!") ? "true" : "false");
    return 0;
}

