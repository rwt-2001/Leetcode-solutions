class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> oneRow(row);
        vector<int> zeroRow(row);
        vector<int> oneCol(col);
        vector<int> zeroCol(col);
        
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j]==0) zeroRow[i]++;
                if(grid[i][j]==1) oneRow[i]++;
            }
        }
        
        for(int i = 0;i<col;i++){
            for(int j = 0;j<row;j++){
                if(grid[j][i] == 0) zeroCol[i]++;
                 if(grid[j][i]==1) oneCol[i]++;
            }
        }
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                grid[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }
        return grid;
    }
};