class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> mp;
        for(auto num: nums)
        {
            mp[num]++;
        }
        
        
        int ans = 0;
        for(auto val: mp)
        {
            if(val.second > 1)
            {
                for(int i = 2; i <= val.second; i++)
                {
                    ans += (i-1);
                }
                
            }
        }
        
        return ans;
    }
};