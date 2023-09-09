class Solution {
    vector<vector<int>> dp;
public:
    int solve(int index, vector<int> &nums,int target)
    {
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[index][target] != -1) return dp[index][target];        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += solve(i, nums, target - nums[i]);
        }
        
        return dp[index][target] = ans;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<vector<int>> (nums.size(), vector<int> (target+1, -1));
        return solve(0, nums, target);
    }
};