class Solution {
public:
    bool canMake(int number, vector<int> nums)
    {
        long long rem = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] - rem > number) return false;
            
            rem = number - (nums[i] - rem);    
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int maxNum = -1;
        int l = 0, r = 1e9;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            
            if(canMake(mid, nums))
            {
                maxNum = mid;
                r = mid - 1;
            }else{
                l = mid+1;
            }
        }
        
        return maxNum;
    }
};