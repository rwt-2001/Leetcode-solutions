class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> dp(nums.size(),{1, -1});
        int maxLen = 1;
        int startIndex = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                
                if(nums[j] % nums[i] == 0 && dp[i].first < dp[j].first + 1)
                {
                    if(maxLen < dp[j].first + 1)
                    {
                        maxLen = dp[j].first  + 1;
                        startIndex = i;
                    }
                    dp[i] = {dp[j].first + 1, j};
                }
            }
        }
        
        
        vector<int> ans;
        
        while(startIndex != -1){
            ans.push_back(nums[startIndex]);
            startIndex = dp[startIndex].second;
        }
        
        return ans;
    }
};