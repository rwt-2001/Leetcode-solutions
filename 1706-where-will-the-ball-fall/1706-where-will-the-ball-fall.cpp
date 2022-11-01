class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j){
        
        if(i==grid.size()) return j;
        int curVal = grid[i][j];
        
        if(curVal == -1){
            if(j-1 < 0 || curVal != grid[i][j-1]) return -1;
            return solve(grid, i+1, j + curVal);
        }
        
        if(j + 1 >= grid[0].size() || curVal != grid[i][j+1]) return -1;  
        
        return solve(grid, i+1, j + curVal);
         
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        vector<int> ans(grid[0].size(), -1);
        
        for(int col = 0;col < grid[0].size(); col++)
            ans[col] = solve(grid,0,col);
        
        return ans;
        
    }
};