class Solution {
public:
        vector<vector<int>> ans;
    vector<int> mp;
    vector<int> paths;
    void solve(vector<int> &nums, int index)
    {
        if(index ==  nums.size()){
            ans.push_back(paths);
            return;
        }
        map<int,int> mp1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[i]==0 && !mp1[nums[i]]){
                paths.push_back(nums[i]);
                mp[i] = 1;
                mp1[nums[i]]++;
                solve(nums, index + 1);
                paths.pop_back();
                mp[i] = 0;
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)  {
        mp = vector<int>(nums.size(), 0);
        solve(nums, 0);
        return ans;
    
    }
};