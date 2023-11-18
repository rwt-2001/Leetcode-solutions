class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int ans = 1;    
        long curr = nums[0];
        while(r < nums.size())
        {
            
            
            int target = nums[r];
                
           
            if(1l*target*(r - l + 1) <=curr + k )
            {
                ans = max(r - l +1, ans);
                r++;
                if(r < nums.size())
                    curr += nums[r];
            }
            else{
                
            
                curr -= nums[l];
                l++;
            }
            
        }
        return ans;
        
    }
};
    
    