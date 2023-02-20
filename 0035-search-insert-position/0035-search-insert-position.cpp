class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
           
            int mid = round((l + r) / 2);
            
            if(nums[mid] > target)
            {
                r = mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] == target){
                return  mid;
            }
        }

        if(nums[l] < target) return l + 1;
        return l;
    }
};