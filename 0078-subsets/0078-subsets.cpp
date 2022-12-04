class Solution {
    vector<vector<int>> ans;
public:
    void dfs(int index, vector<int> &nums, vector<int> &subset){
        
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        
        //PICK
        subset.push_back(nums[index]);
        dfs(index + 1, nums, subset);
        
        
        //NOT PICK
        subset.pop_back();
         dfs(index + 1, nums, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        dfs(0, nums, subset);
        return ans;
    }
};