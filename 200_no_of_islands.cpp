/**Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water. **/

#include "iostream"
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid){
    int noOfIslands=0;
    int rows=grid.size();
    if(rows==0)
      return 0;
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    for(int i = 0; i<rows; i++) {
      for(int j = 0; j<cols; j++) {
        if(grid[i][j]==1 && ~visited[i][j]){
          noOfIslands++;
          markIslands(grid, visited, i, j, rows, cols);
        }
      }
    }
  }

  void markIslands(vector<vector<char>>& grid,vector<vector<bool>> &visited, int i, int j, int rows, int cols) {
    visited[i][j]=1;
    if(i>0 && grid[i-1][j]==1 && ~visited[i-1][j])
      markIslands(grid, visited, i-1, j, rows, cols);
    if(j>0 && grid[i][j-1]==1 && ~visited[i][j-1])
      markIslands(grid, visited, i, j-1, rows, cols);
    if(i<(rows-1) && grid[i+1][j]==1 && ~visited[i+1][j])
      markIslands(grid, visited, i+1, j, rows, cols);
    if(j<(cols-1) && grid[i][j+1]==1 && ~visited[i][j+1])
      markIslands(grid, visited, i, j+1, rows, cols);
  }
};

int main() {
  Solution islands;
  vector<vector<char>> grid_input{{"11110"},{"11010"},{"11000"},{"00000"}};
  int islandCount = islands.numIslands(grid_input);
  std::cout<<"Island Input"<<endl;
  for(int i=0; i<grid_input.size(); i++){
    for(int j = 0; j<grid_input[i].size(); j++)
      cout<<(char)grid_input[i][j];
    cout<<endl;
  }
  cout<<"Number of islands: "<<islandCount<<endl;
  return 0;
}
