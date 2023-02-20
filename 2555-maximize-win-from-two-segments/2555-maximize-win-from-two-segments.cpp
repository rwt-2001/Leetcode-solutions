class Solution {
public:
    int maximizeWin(vector<int>& pp, int k) {
        
        int n = pp.size();
        int start = 0;
        vector<int> dp(n+1);
        
        int ans = 0;
        for(int end = 0; end < n;end++)
        {
            while(pp[end] - pp[start] > k)
                start++;
            dp[end + 1] = max(dp[end], end - start + 1);
            ans = max(ans, dp[start] + end - start + 1);
        }
        
        return ans;
    } 
};
