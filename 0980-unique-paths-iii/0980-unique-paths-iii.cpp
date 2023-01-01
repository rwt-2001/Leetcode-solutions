class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int i, int j){
        
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j]==3 || grid[i][j] == -1){
            return 0;
        }
        
        if(grid[i][j] == 2){
            for(auto &row : grid){
                for(auto &col : row){
                    if(col == 0) return 0;
                }
            }
            return 1;
        }
        
        grid[i][j] = 3;
        
        int a = solve(grid, i + 1, j);
        int b = solve(grid, i , j + 1);
        int c = solve(grid, i- 1, j);
        int d = solve(grid, i, j-1);
        
        grid[i][j] = 0;
        return a + b + c +d;
        
        
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int flag = 0;
        int ans = 0;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0;j < grid[i].size();j++){
                if(grid[i][j] == 1){
                    ans = solve(grid,i, j);
                    flag = 1;
                }
            }
            if(flag) break;
        }
        return ans;
    }
};