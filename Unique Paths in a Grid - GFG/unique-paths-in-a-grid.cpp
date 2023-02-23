//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int MOD = 1e9 + 7;
class Solution {
  public:
    int f(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
         if(r > m || c > n || grid[r][c]==0) return 0;
        if(r==m && c == n) return 1;
       
        if(dp[r][c] != -1) return dp[r][c];
        int values = (1LL* f(r+1, c, grid, dp) + f(r, c+1, grid, dp)) % MOD;
        
        return dp[r][c] = values;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return f(0,0, grid, dp);
        vector<vector<int>> dp(n+1, vector<int>(m + 1, 0));
        dp[n][m-1] = grid[n-1][m-1];
        for(int r = n-1; r >= 0; r--)
        {
            for(int c = m-1; c>=0; c--)
            {
                if(grid[r][c] > 0)
                    dp[r][c] = (1LL* dp[r+1][c] + dp[r][c+1]) % MOD;
            }
        }
        
        //Tabulation
        
        return dp[0][0];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends