class Solution {
    int mod = 1e9 + 7;
public:
    int solve(int low, int high, int zero, int one, int len, int choosen, vector<vector<int>> &dp)
    {
        if(len > high) return 0;
        
        if(dp[len][choosen] != -1) return dp[len][choosen];
        long long ans = 0;
        
        ans += solve(low, high, zero, one, len + zero, 0, dp) %mod;
        ans += solve(low, high, zero, one, len + one, 1, dp)%mod;
        
        return dp[len][choosen] = (ans + (len >= low && len <= high))%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<vector<int>> dp(high+1, vector<int>(2, -1));
        
        return (solve(low, high, zero, one, 0+one,1, dp)%mod + solve(low, high, zero, one, 0+zero,0, dp)%mod)%mod;
    }
};