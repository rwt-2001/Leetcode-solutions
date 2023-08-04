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
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[i]==0){
                paths.push_back(nums[i]);
                mp[i] = 1;
                solve(nums, index + 1);
                paths.pop_back();
                mp[i] = 0;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        mp = vector<int>(nums.size(), 0);
        solve(nums, 0);
        return ans;
    }
};