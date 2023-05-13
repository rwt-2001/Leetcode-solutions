class Solution {
    int mod = 1e9 + 7;
public:
    int solve(int low, int high, int zero, int one, int len, vector<int> &dp)
    {
        if(len > high) return 0;
        
        if(dp[len] != -1) return dp[len];
        long long ans = 0;
        ans += solve(low, high, zero, one, len + zero, dp) %mod;
        ans += solve(low, high, zero, one, len + one, dp)%mod;
        
        return dp[len] = (ans + (len >= low && len <= high))%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        
        return solve(low, high, zero, one, 0, dp)%mod ;
    }
};