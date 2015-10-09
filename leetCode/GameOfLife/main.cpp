#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    void gameOfLife( std::vector<std::vector<int>>& board )
    {
        for ( int i = 0; i < ( int ) board.size(); ++i )
        {
            for ( int j = 0; j < ( int ) board[i].size(); ++j )
            {
                int nb_life = nbOfLife( board, i, j );
                if ( ( ( board[i][j] == 0 ) && ( 3 == nb_life ) ) || ( ( board[i][j] == 1 ) && ( nb_life >= 2 ) && ( nb_life <= 3 ) ) )
                {
                    board[i][j] |= 2;
                }
            }
        }

        for ( int i = 0; i < ( int ) board.size(); ++i )
        {
            for ( int j = 0; j < ( int ) board[i].size(); ++j )
            {
                board[i][j] >>= 1;
            }
        }
    }
    int nbOfLife( std::vector<std::vector<int>>& board, int i, int j )
    {
        int nb_life = 0;
        for ( int k =  std::max( i - 1, 0 ); k <= std::min( i + 1, ( int ) board.size() - 1 ); ++k )
        {
            for ( int l =  std::max( j - 1, 0 ); l <= std::min( j + 1, ( int ) board[i].size() - 1 ); ++l )
            {
                if ( ( l == j ) && ( k == i ) )
                {
                    continue;
                }
                if ( 1 == ( board[k][l] % 2 ) )
                {
                    ++ nb_life;
                }
            }
        }
        return nb_life;
    }
};

int main()
{
    std::vector<std::vector<int> > board = {{1, 1}};
    Solution s;
    s.gameOfLife( board );
    for ( int i = 0; i < ( int ) board.size(); ++i )
    {
        for ( int j = 0; j < ( int ) board[i].size(); ++j )
        {
            printf( "%d", board[i][j] );
        }
        printf( "\n" );
    }
    return 0;
}
