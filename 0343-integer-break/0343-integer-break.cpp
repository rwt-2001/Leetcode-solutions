class Solution {
    vector<int> dp;
public:
    int f(int n)
    {
        if(n == 0) return 1;
        if(n < 0) return -1;
        if(dp[n]!=-1)return dp[n]; 
        int ans = -1;
        for(int i = 1; i <= n ; i ++)
        {
            ans = max(ans, f(n - i) * i);
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        dp = vector<int> (n+1, -1);
        if(n==3) return 2;
        if(n == 2) return 1;
        return f(n);
    }
};