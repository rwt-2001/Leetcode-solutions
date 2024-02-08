class Solution {
    vector<int> dp;
    int solve(int n)
    {
        if(n==0){
            return 0;
        }
        if(n < 0)
        {
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        int ans = n;
        for(int i = 1; i <= sqrt(n);i++)
        {
            ans = min(ans, solve(n - (i*i)));
        }
        
        return dp[n] =  ans + 1;
    }
public:
    int numSquares(int n) {
        dp = vector<int> (n+1, -1);
        return solve(n);
    }
};