class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = floor(nums.size() / 3);
        map<int,pair<int,int>> mp;
        vector<int> ans;
        
        for(auto &num: nums)
        {
            mp[num].first++;
            if(mp[num].first > n && !mp[num].second)
            {
                ans.push_back(num);
                mp[num].second = 1;
            }
        }
        return ans;
    }
};