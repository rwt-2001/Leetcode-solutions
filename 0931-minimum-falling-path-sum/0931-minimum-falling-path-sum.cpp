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
        
        int ans = INT_MAX;
        vector<vector<int>> dp(matrix.size(), (vector<int> (matrix[0].size(), -1)));
        for(int i = 0;i<matrix[0].size();i++){
            ans = min(ans, f(matrix, 0, i, dp));
        }
        return ans;
    }
};