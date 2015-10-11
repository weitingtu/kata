#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    void setZeroes( std::vector<std::vector<int>>& matrix )
    {
        int mask = -1;
        for ( int i = 0; i < ( int )matrix.size(); ++i )
        {
            bool clear = false;
            for ( int j = 0; j < ( int )matrix[i].size(); ++j )
            {
                if ( matrix[i][j] != 0 )
                {
                    continue;
                }
                if ( -1 == mask )
                {
                    mask = i;
                    break;
                }
                matrix[mask][j] = 0;
                clear = true;
            }
            if ( clear )
            {
                for ( int j = 0; j < ( int )matrix[i].size(); ++j )
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if ( -1 == mask )
        {
            return;
        }
        for ( int j = 0; j < ( int )matrix[mask].size(); ++j )
        {
            if ( 0 == matrix[mask][j] )
            {
                for ( int i = 0; i < ( int )matrix.size(); ++i )
                {
                    matrix[i][j] = 0;
                }
            }
            matrix[mask][j] = 0;
        }
    }
};

// To execute C++, please define "int main()"

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution s;
    s.setZeroes( matrix );
    for ( int i = 0; i < ( int )matrix.size(); ++i )
    {
        for ( int j = 0; j < ( int )matrix[i].size(); ++j )
        {
            printf( "%d ", matrix[i][j] );
        }
        printf( "\n" );
    }

    return 0;
}

