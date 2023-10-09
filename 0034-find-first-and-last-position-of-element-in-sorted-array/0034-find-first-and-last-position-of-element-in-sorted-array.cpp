class Solution {
public:
    int f(vector<int> &nums, int target, bool first)
    {
        int i = 0;
        int j = nums.size() - 1;
        int ans = -1;
        
        while(i <= j)
        {
            
            int mid = i + (j - i)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                if(first) j = mid - 1;
                else i = mid + 1;
            }else if(nums[mid] > target)
            {
                j = mid - 1;
            }else{
                i = mid + 1;
            }
            
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {f(nums, target, true), f(nums, target, false)};
    }
};