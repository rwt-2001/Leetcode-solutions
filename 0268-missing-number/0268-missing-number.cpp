class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(n);
        int zero = false;
        for(int i = 0; i < n; i++)
        {
            int index = abs(nums[i]);
            if(nums[index] == 0) zero = true;
            nums[index] = -1*abs(nums[index]);
            
        }
        
        
        int ans = -1;
        for(int i = 0; i <= n;i++)
        {
            if(nums[i]==0 && zero) continue;
            if(nums[i] >= 0) return i;
        }
        
        return -1;
    }
};