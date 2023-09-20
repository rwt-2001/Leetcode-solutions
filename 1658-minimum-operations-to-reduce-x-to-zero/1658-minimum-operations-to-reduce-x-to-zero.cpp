class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;
        if(target == 0) return nums.size();
        int ans = -1;
        int j = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            target -= nums[i];
            while(target < 0 && j < i)
            {
                target += nums[j++];
                
            }
            if(target == 0)
            {
                ans = max(ans, i - j + 1);
                target += nums[j++];
            }
        }
        
        return ans == -1 ? -1 : nums.size() - ans;
    }
};