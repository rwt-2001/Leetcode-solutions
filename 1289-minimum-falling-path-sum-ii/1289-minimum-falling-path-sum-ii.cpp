class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = vector<vector<int>> (grid.size(), vector<int>(grid[0].size(), 0));
        
        int lr = grid.size() - 1;
        for(int i = 0; i < grid[0].size(); i++)
        {
            dp[lr][i] = grid[lr][i];
        }
        
        
        for(int i = grid.size() - 2; i >= 0; i--)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                int num = INT_MAX;
                for(int k = 0; k < grid[0].size(); k++)
                {
                    if(k==j) continue;
                    num = min(num, dp[i+1][k]);
                }
                
                dp[i][j] = grid[i][j] + num;
            }
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};