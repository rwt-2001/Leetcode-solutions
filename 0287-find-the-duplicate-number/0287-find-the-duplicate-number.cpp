class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
        int ans = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            
            if(nums[abs(nums[i]) - 1] < 0)
            {
                ans = abs(nums[i]);
                break;
            }
            
            nums[abs(nums[i]) - 1] = -1*nums[abs(nums[i]) - 1] ;
        }
        
        return ans;
    }
};