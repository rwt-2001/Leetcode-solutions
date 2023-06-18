class Solution {
    int mod = 1e9 + 7;
public:
    int dfs(int prev, vector<vector<int>> &grid, vector<vector<long long>> &dp, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]<= prev)
        {
            return 0;
        }
        if(dp[i][j] != 1) return dp[i][j];
        int curLen = dp[i][j];
        
        
        curLen += dfs(grid[i][j], grid, dp, i + 1, j);
        curLen += dfs(grid[i][j], grid, dp, i - 1, j);
        curLen += dfs(grid[i][j], grid, dp, i, j + 1);
        curLen += dfs(grid[i][j], grid, dp, i, j - 1);
        
        return dp[i][j] = curLen % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<long long>> dp(grid.size(), vector<long long> (grid[0].size(), 1));
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j  < grid[0].size(); j++)
            {
                if(dp[i][j]==1)
                {
                    dfs(-1, grid, dp, i, j);
                }
            }
        
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j  < grid[0].size(); j++)
            {
                // cout<<dp[i][j]<<" ";
                ans = ((1LL* ans + dp[i][j])%mod);
            }
            // cout<<endl;
        }
        
        return ans;
    }
};



