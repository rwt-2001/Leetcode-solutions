class Solution {
    vector<vector<int>> dp;
public:
    int solve(vector<vector<int>> &arr, int i, int j)
    {
        if(i >= arr.size() || i < 0 || j >= arr[0].size() || j < 0) return 1e8;
        
        if(i == arr.size() - 1) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        ans = min(ans, arr[i][j] + solve(arr, i+1, j));
        
        ans = min(ans, arr[i][j] + solve(arr, i+1, j -1));
        
        ans = min(ans, arr[i][j] + solve(arr, i + 1, j+1));
        
        
        return dp[i][j]=ans;
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
     dp = vector<vector<int>> (matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int lastRow = matrix.size() - 1;
        for(int i = 0; i < matrix[0].size(); i++){
            dp[lastRow][i] = matrix[lastRow][i];
        }
        
        
        for(int i = matrix.size() - 2; i >= 0; i--)
        {
            for(int j = matrix[0].size() -1; j >= 0; j--)
            {
                
                int num = INT_MAX;
                
                if(j-1 >= 0)
                {
                    num = min(num, dp[i+1][j-1]);
                }
                if(j + 1 < matrix[0].size())
                {
                    num = min(num, dp[i+1][j+1]);
                }
                
                dp[i][j] = matrix[i][j] + min(num, dp[i+1][j]);
            }
        }
        
        
        return *min_element(dp[0].begin(), dp[0].end());
        
    }
};