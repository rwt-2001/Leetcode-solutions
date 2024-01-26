class Solution {
    int mod = 1e9 + 7;
    
public:
    int solve(int m, int n, int i, int j, int movesLeft, vector<vector<vector<int>>> &dp){
        if(i < 0 || i == m || j < 0 || j == n) return 1;
        if(movesLeft == 0) return 0;
        if(dp[i][j][movesLeft] != -1) { return dp[i][j][movesLeft];}
        int ans = 0;
     
        movesLeft -= 1;
        ans = (ans + solve(m,n,i+1,j,movesLeft, dp )) % mod;
        ans = (ans + solve(m,n,i,j+1,movesLeft, dp ))% mod;
        ans = (ans +solve(m,n,i-1,j,movesLeft, dp ))% mod;
        ans = (ans +solve(m,n,i,j-1,movesLeft, dp ))% mod;   
        
        
        return dp[i][j][movesLeft + 1] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(maxMove + 1, -1)));
        return solve(m,n,startRow, startColumn, maxMove, dp);
    }
};