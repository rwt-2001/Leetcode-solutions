class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        if(i< 0 || j < 0 || i>=grid.size() || j >= grid[0].size())
        {
            return INT_MAX;
        }
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return grid[i][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(grid, i + 1, j, dp), solve(grid, i , j+1, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid,0,0, dp);
    }
};