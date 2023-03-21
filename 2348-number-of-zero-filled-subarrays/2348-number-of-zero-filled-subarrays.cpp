class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            long long cnt = 0;
            while(i < nums.size() && nums[i]==0)
            {
                cnt++;
                i++;
            }
            
            ans += cnt*(cnt+1)/2;
        }
        
        
        return ans;
    }
};