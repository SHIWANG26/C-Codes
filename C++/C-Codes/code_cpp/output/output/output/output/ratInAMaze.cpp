#include <vector>
#include <iostream>
using namespace std;

bool isSafe(int x, int y, int row, int col, int maze[3][3], vector<vector<bool>> &visited)
{
    if ((x >= 0 && x <= row) && (y >= 0 && y <= col) && (maze[x][y] == 1) && (visited[x][y] == false))
    {
        return true;
    }
    else
        return false;
}

void solveMaze(int maze[3][3], int row, int col, int srcx, int srcy, vector<vector<bool>> &visited, vector<string> &path, string output)
{
    // base case
    if (srcx == row - 1 && srcy == col - 1)
    {
        // ans found
        path.push_back(output);
        return;
    }
    // down=i+1
    if (isSafe(srcx + 1, srcy, row, col, maze, visited))
    {
        visited[srcx + 1][srcy] = true;
        solveMaze(maze, row, col, srcx + 1, srcy, visited, path, output + 'D');
        // backtrack
        visited[srcx + 1][srcy] = false;
    }
    // up= i-1
    if (isSafe(srcx - 1, srcy, row, col, maze, visited))
    {
        visited[srcx - 1][srcy] = true;
        solveMaze(maze, row, col, srcx + 1, srcy, visited, path, output + 'U');
        // backtrack
        visited[srcx - 1][srcy] = false;
    }
    // right=j+1
    if (isSafe(srcx, srcy + 1, row, col, maze, visited))
    {
        visited[srcx][srcy + 1] = true;
        solveMaze(maze, row, col, srcx, srcy + 1, visited, path, output + 'R');
        // backtrack
        visited[srcx][srcy + 1] = false;
    }
    // left=j-1
    if (isSafe(srcx, srcy - 1, row, col, maze, visited))
    {
        visited[srcx][srcy - 1] = true;
        solveMaze(maze, row, col, srcx, srcy - 1, visited, path, output + 'L');
        // backtrack
        visited[srcx][srcy - 1] = false;
    }
}

int main()
{
    int maze[3][3] = {{1, 0, 0},
                      {1, 1, 0},
                      {1, 1, 1}};
    int row = 3, col = 3;
    if (maze[0][0]==0)
    {
        cout<<"No path exists"<<endl;
        return 0;
    }
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[0][0] = true;
    vector<string> path;
    string output = "";
    solveMaze(maze, row, col, 0, 0, visited, path, output);
    cout << "Printing the result: " << endl;
    for (auto n : path)
    {
        cout << n << " ";
    }
    cout << endl;
    if (path.size() == 0)
    {
        cout<<"No path exists!"<<endl;
    }
    
    return 0;
}
