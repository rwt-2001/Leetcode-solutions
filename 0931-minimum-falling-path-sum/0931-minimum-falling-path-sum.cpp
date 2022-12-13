class Solution {
    int f(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp){
        
        if(i == matrix.size()) return 0;
        if(j < 0 || j >= matrix[0].size()) return 1e6;
        if(dp[i][j] != -1) return dp[i][j];
        int cl = f(matrix, i + 1, j - 1, dp);
        int cb = f(matrix, i + 1, j, dp);
        int cr = f(matrix, i + 1, j+1, dp);
        
        return dp[i][j] = matrix[i][j] + min({cl, cb, cr});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // int ans = INT_MAX;
        // vector<vector<int>> dp(matrix.size(), (vector<int> (matrix[0].size(), -1)));
        // for(int i = 0;i<matrix[0].size();i++){
        //     ans = min(ans, f(matrix, 0, i, dp));
        // }
        // return ans;
        
        //Tab
        int col = matrix[0].size() - 1;
        int row = matrix.size() - 1;

        
        
        for(int i = row-1; i>=0; i--){
            for(int j = col; j>= 0; j--){
                int cl = 1e6, cb = 1e6, cr = 1e6;
                
                if(j-1 >= 0)
                    cl = min(cl, matrix[i + 1][j - 1]);
                
                cb = min(cb, matrix[i + 1][j]);
                
                if(j + 1 <= col)
                    cr = min(cr, matrix[i + 1][j+1]);
                
                matrix[i][j] = matrix[i][j] + min({cl, cr, cb});
            }
        }
        
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};