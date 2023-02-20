class Solution {
public:
    bool dfs(vector<vector<int>> &grid, int m, int n)
    {
        if(m == grid.size() - 1 && n == grid[0].size() - 1) return true;
        if(m >= grid.size() || n >= grid[0].size() || grid[m][n]==0) return false;
        
     
        grid[m][n] = 0;
        bool nr = dfs(grid, m + 1, n);
        if(nr) return nr;
        bool nc = dfs(grid, m , n + 1);
        
        return nc || nr;
        
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
 
       
        if(dfs(grid, 0, 0) == false) return true;
        grid[0][0] = 1;
        return !dfs(grid,0,0);
    }
};