class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            
            if(dp.size() == 0 )
            {
                dp.push_back(nums[i]);
            }else{
                
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                if(itr == dp.size())
                {
                    dp.push_back(nums[i]);

                }else
                dp[itr] = nums[i];
            }
        }
        
        return dp.size();
    }
};