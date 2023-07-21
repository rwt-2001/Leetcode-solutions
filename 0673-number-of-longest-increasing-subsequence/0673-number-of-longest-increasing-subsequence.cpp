class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> ss(nums.size(), 1);
        int maxLen = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i - 1; j >=0 ; j--)
            {
                if(nums[j] < nums[i])
                {
                    
                    if(dp[j] + 1 == dp[i])
                    {
                        ss[i]+=ss[j];
                    }else if(dp[j] + 1 > dp[i]){
                        ss[i] = ss[j];
                        dp[i] = dp[j] + 1;
                        maxLen = max(maxLen, dp[i]);
                    }
                    
                }
            }
        }
        // cout<<endl;
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // cout<<dp[i]<<" ";
            if(dp[i] == maxLen)
            {
                count += ss[i];
            }
        }
        return count;
    }
};