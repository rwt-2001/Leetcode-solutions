class Solution {
    int mod = 1e9 + 7;
public:
    int rev_number(int num)
    {
        int new_num = 0;
        while(num)
        {
            new_num *= 10;
            new_num+= (num%10);
            num/=10;
        }
        return new_num;
    }
    int countNicePairs(vector<int>& nums) {
        
        
        
        unordered_map<int,int> mp;
        int ans = 0;
       
        for(int i = 0;i < nums.size(); i++)
        {
            
            int num = rev_number(nums[i]) - nums[i];
            mp[num]++;
            if(mp[num] > 1)
            {
                ans = (ans*1L +  mp[num]-1) % mod;
            }
        
        }
        return ans;
    }
};

// num i  - rev num_ i = numj - rev nums 