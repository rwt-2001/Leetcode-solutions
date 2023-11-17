class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        
        int ans = nums[i] + nums[j];
        while(i < j)
        {
            ans = max(nums[i++] + nums[j--], ans);
        }
        
        return ans;
    }
};