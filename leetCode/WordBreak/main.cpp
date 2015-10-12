#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::unordered_set<std::string>& wordDict) {
        if((int) s.size() == 0)
            return false;
        std::vector<bool> dp((int)s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= (int)s.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(dp[j] && (wordDict.find(s.substr(j, i - j)) != wordDict.end() ))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[(int)s.size()];
        
    }
};


// To execute C++, please define "int main()"

int main() {
  
    std::unordered_set<std::string> wordDict({"leet", "code"});
    Solution s;
    printf("%s\n", s.wordBreak("leetcode", wordDict) ? "true" : "false");
    printf("%s\n", s.wordBreak("leet", wordDict) ? "true" : "false");
    printf("%s\n", s.wordBreak("lecode", wordDict) ? "true" : "false");
    wordDict = std::unordered_set<std::string>({});
    printf("%s\n", s.wordBreak("leetcode", wordDict) ? "true" : "false");
    printf("%s\n", s.wordBreak("", wordDict) ? "true" : "false");
    return 0;
}

