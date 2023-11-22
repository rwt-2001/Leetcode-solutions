class Solution {
    int mod = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> rev(nums.size());
        
        for(int i = 0;i < nums.size(); i++)
        {
            
            string cur_num = to_string(nums[i]);
            reverse(cur_num.begin(), cur_num.end());
            rev[i] = nums[i] - stoi(cur_num);
        }
        
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto num: rev)
        {
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