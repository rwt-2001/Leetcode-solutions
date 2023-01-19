class Solution {
public:
    
    int subarraysDivByK(vector<int>& nums, int k) {
        
        vector<int> mp(k);
        int sum = 0;
        mp[0]=1;
        
        int ans = 0;
        for(auto num: nums)
        {
            sum+=num;
            int remainder = sum%k;
            if(remainder < 0)
            {
                remainder += k;
            }
            ans += mp[remainder];
            mp[remainder]++;
        }
        return ans;
        
    }
};