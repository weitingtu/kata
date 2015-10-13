#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_set>

class Solution {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms) {
        (void) rooms;
        for(int i = 0; i < (int) rooms.size(); ++i)
        {
            for(int j = 0; j < (int) rooms[i].size(); ++j)
            {
                if(rooms[i][j] != 0)
                    continue;
                fillPath(rooms, i, j, 0);
            }
        }
    }
    
    void fillPath(std::vector<std::vector<int>>& rooms, int i, int j, int dist)
    {
        if((i < 0) || (i >= (int)rooms.size()) || (j < 0) || (j >= (int)rooms[i].size()) || (rooms[i][j] < dist))
            return;
        rooms[i][j] = dist;
        ++dist;
        fillPath(rooms, i - 1,     j, dist);
        fillPath(rooms, i + 1,     j, dist);
        fillPath(rooms,     i, j - 1, dist);
        fillPath(rooms,     i, j + 1, dist);
    }
};

// To execute C++, please define "int main()"

int main() {
    std::vector<std::vector<int>> rooms = 
    {{2147483647,        -1,         0,2147483647},
     {2147483647,2147483647,2147483647,        -1},
     {2147483647,        -1,2147483647,        -1},
     {0,                 -1,2147483647,2147483647}};
    
    Solution s;
    s.wallsAndGates(rooms);
    for(int i = 0; i < (int) rooms.size(); ++i)
    {
        for(int j = 0; j < (int) rooms[i].size(); ++j)
        {
            if(rooms[i][j] == -1)
                printf("# ");
            else 
                printf("%d ", rooms[i][j]);
        }
        printf("\n");
    }
    return 0;
}
