#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, const std::string& word) 
    {
        for(int i = 0; i < (int)board.size(); ++i)
        {
            for(int j = 0; j <(int)board[i].size();++j)
            {
                if(exist(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool exist(std::vector<std::vector<char>>&board, int x, int y, const std::string& word, int start)
    {
        if(start >= (int)word.size())
            return true;
        if((x < 0) || (x >= (int) board.size()) || (y < 0) || (y >= (int) board[x].size()) )
            return false;
        if(board[x][y] != word[start])
            return false;
        ++start;
        char c = board[x][y];
        board[x][y] = '#';
        bool res = exist(board, x - 1, y, word, start) || exist(board, x + 1, y, word, start) || exist(board, x, y - 1, word, start) || exist(board, x, y + 1, word, start);
        board[x][y] = c;
        return res;
    }
};


// To execute C++, please define "int main()"

int main() {
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'},
                                            {'S', 'F', 'C', 'S'},
                                            {'A', 'D', 'E', 'E'}};
    Solution s;
    printf("%s\n", s.exist(board, "ABCCED") ? "true" : "false");
    printf("%s\n", s.exist(board, "SEE")    ? "true" : "false");
    printf("%s\n", s.exist(board, "ABAB")   ? "true" : "false");
    board = {{}};
    printf("%s\n", s.exist(board, "ADEE")   ? "true" : "false");
    printf("%s\n", s.exist(board, "")       ? "true" : "false");
    board = {{'a'}};
    printf("%s\n", s.exist(board, "a")      ? "true" : "false");
 
    return 0;
}

