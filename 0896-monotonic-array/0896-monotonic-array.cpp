class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isInc = false;
        bool isDec = false;
        
        for(int i = 1; i < nums.size() ;i++)
        {
            if(nums[i-1] < nums[i]) isInc = true;
            if(nums[i-1] > nums[i]) isDec = true;
            if((isInc && isDec)) return false;
        }
        
        return true;
    }
};