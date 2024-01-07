class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<long long,int>> dp(nums.size());
        long long sum = 0;
        long long n = nums.size();
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                long long diff = 1ll*nums[i] - 1ll*nums[j];
                dp[i][diff] += dp[j][diff] + 1;
                sum += dp[j][diff] + 1;
            }
        }
        
        return sum - ((n*(n-1))/2);
    }
};