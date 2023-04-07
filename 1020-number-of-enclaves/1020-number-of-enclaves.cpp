class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>> &grid, int &num)
    {
        
        if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() -1) 
            return false;
        if(grid[i][j]==0) return true;
        grid[i][j] = 0;
        num++;
        bool l = dfs(i, j-1, grid, num);
        bool t = dfs(i-1, j, grid, num);
        bool r = dfs(i, j+1, grid, num);
        bool b = dfs(i+1, j, grid, num);
        
        return l && t && r && b;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                
                if(grid[i][j]==1)
                {
                    // cout<<i<<" "<<j<<endl;
                    int ones = 0;
                    if(dfs(i, j, grid, ones))
                    {
                        ans += ones;
                    }
                }
            }
        }
        
        return ans;
    }
};