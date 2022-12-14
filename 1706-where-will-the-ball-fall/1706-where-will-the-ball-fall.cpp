class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        
        if(i==grid.size()) return j;
        if(dp[i][j] != -1) return dp[i][j];
        int curVal = grid[i][j];
        
        if(curVal == -1){
            if(j-1 < 0 || curVal != grid[i][j-1]) return dp[i][j] = -1;
            return dp[i][j] = solve(grid, i+1, j + curVal, dp);
        }
        
        if(j + 1 >= grid[0].size() || curVal != grid[i][j+1]) return dp[i][j] = -1;  
        
        return dp[i][j] = solve(grid, i+1, j + curVal, dp);
         
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        vector<int> ans(grid[0].size(), -1);
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(), -1));
        for(int col = 0;col < grid[0].size(); col++)
            ans[col] = solve(grid,0,col, dp);
        
        return ans;
        
    }
};