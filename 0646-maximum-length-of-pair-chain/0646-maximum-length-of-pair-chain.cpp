class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        
        vector<int> dp(pairs.size(), 1);
        
        int ans = 1;
        
        for(int i = pairs.size() - 1; i >= 0 ; i--)
        {
            for(int j = i + 1; j < pairs.size(); j++)
            {
                if(pairs[i][1] < pairs[j][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};