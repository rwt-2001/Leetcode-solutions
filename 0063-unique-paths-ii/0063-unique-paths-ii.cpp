class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if(i<0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1)
        {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(i + 1 == grid.size() && j + 1 == grid[0].size()) return 1;
        
        
        
        int ans = 0;
        
        ans += solve(i + 1, j, grid);
        ans += solve(i, j+1, grid);
        
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        dp = vector<vector<int>> (grid.size(), vector<int>(grid[0].size(), -1));
        return solve(0,0, grid);
    }
};