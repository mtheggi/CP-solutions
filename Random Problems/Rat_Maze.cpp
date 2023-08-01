// Backtracking Simple problem ;
/*
2D maze is given where C is the is position to a piece of cheese ,# is a wall , R is the position of a rate.
what is the different paths that the rat can take to reach the piece of cheese if he only move (R) right
or (D) down on the empty cell is denoted by (.) ???
! exampele input :
5 4
.R.#
....
#...
#...
..C.
! output :
RDDDD
DRDDD
DDRDD
DDDRD
DDDDR
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
string path = "";
vector<vector<char>> maze;
void MazeSolve(int row, int col)
{
    if (row >= n || col >= m)
        return;
    if (maze[row][col] == '#')
        return;
    if (maze[row][col] == 'C')
    {
        cout << path << endl;
        return;
    }
    path.push_back('R');
    MazeSolve(row, col + 1);
    path.pop_back();
    path.push_back('D');
    MazeSolve(row + 1, col);
    path.pop_back();
}
int main()
{
    cin >> n >> m;
    vector<char> random(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> random[j];
        }
        maze.push_back(random);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; i < m; j++)
            if (maze[i][j] == 'R')
                MazeSolve(i, j);

    return 0;
}