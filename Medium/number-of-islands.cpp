class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    count++;
                    callDFS(grid,i,j);
                }
            }
        }
        
        return count;
    }
    
    void callDFS(vector<vector<char>> &grid, int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
            return;
        
        grid[i][j] = '0';
        callDFS(grid,i-1,j); // up
        callDFS(grid,i+1,j); // down
        callDFS(grid,i,j-1); // left
        callDFS(grid,i,j+1); // right
    }
};