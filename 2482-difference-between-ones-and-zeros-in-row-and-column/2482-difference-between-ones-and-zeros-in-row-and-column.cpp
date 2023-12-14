class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> verOne(grid.size(), 0), verZero(grid.size(), 0), horOne(grid[0].size(), 0), horZero(grid[0].size(), 0);
        
        
        for(int i = 0; i < grid.size(); i++)
        {
            int sum0 = 0, sum1 = 0;
            for(int j = 0;j < grid[0].size(); j++)
            {
                if(grid[i][j]) sum1++;
                else sum0++;
            }
            verOne[i] = sum1;
            verZero[i] = sum0;
        }
        
        for(int i = 0; i < grid[0].size(); i++)
        {
            int sum0 = 0, sum1 = 0;
            for(int j = 0;j < grid.size(); j++)
            {
                if(grid[j][i]) sum1++;
                else sum0++;
            }
            horOne[i] = sum1;
            horZero[i] = sum0;
        }
        
        
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i = 0; i < grid.size(); i++)
        {
            int sum0 = 0, sum1 = 0;
            for(int j = 0;j < grid[0].size(); j++)
            {
               ans[i][j] = verOne[i] + horOne[j] - verZero[i] - horZero[j];
            }
        }
        
        return ans;
    }
};