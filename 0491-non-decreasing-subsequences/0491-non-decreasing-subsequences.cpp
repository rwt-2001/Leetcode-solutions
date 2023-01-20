class Solution {
    set<vector<int>> res;
public:
    void solve(int index, vector<int> &nums, int size, vector<int> &cur_res)
    {
        if(size > 1){
            res.insert(cur_res);
        }
        int cur_size = cur_res.size();
        int lastNum = -10000;
        for(int i = index;i < nums.size();i++)
        {
            if(cur_size != 0 && cur_res[cur_size - 1] <= nums[i] && lastNum != nums[i])
            {
                cur_res.push_back(nums[i]);
                solve(i + 1, nums, size + 1, cur_res);
                cur_res.pop_back();
                lastNum == nums[i];
            }
            if(cur_size == 0)
            {
                cur_res.push_back(nums[i]);
                solve(i + 1, nums, size + 1, cur_res);
                cur_res.pop_back();
                lastNum == nums[i];
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur_res;
        solve(0, nums, 0, cur_res);
        vector<vector<int>> ans;
        for(auto vec : res)
        {
            ans.push_back(vec);
        }
        
        return ans;
    }
};