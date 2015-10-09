#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <map>
#include <set>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        std::vector<std::string> strs = split_str(str);

        if(strs.size() != pattern.size())
        {
            return false;
        }

        std::set<std::string> unique;
        std::map<char, std::string> mapping;
        for(int i = 0; i < (int) pattern.size(); ++i)
        {
            std::map<char, std::string>::const_iterator ite = mapping.find(pattern[i]);
            if(ite == mapping.end())
            {
                if(unique.find(strs[i]) != unique.end())
                {
                    return false;
                }
                unique.insert(strs[i]);
                mapping[pattern[i]] = strs[i];
                continue;
            }
            if(ite->second != strs[i])
            {
                return false;
            }
        }
        return true;
        
    }

    std::vector<std::string> split_str(const std::string& str)
    {
        std::string s;
        std::vector<std::string> strs;
        for(int i = 0; i < (int)str.size(); ++i) 
        {
            if(str[i] == ' ')
            {
                strs.push_back(s);
                s.clear();
                continue;
            }
            s += str[i];
        }
        strs.push_back(s);
        s.clear();
        return strs;
    }
};

int main()
{
    Solution s;
    assert(s.wordPattern("abba", "dog cat cat dog")  == true);
    assert(s.wordPattern("abba", "dog cat cat fish") == false);
    assert(s.wordPattern("aaaa", "dog cat cat dog")  == false);
    assert(s.wordPattern("abba", "dog dog dog dog")  == false);
    return 0;
}
