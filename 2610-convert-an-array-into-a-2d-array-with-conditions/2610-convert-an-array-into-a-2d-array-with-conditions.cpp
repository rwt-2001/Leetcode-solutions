class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
            
        vector<int> maxRow(nums.size() + 1, 0);
        vector<vector<int>> ans;
        
        for(auto num : nums)
        {
            maxRow[num]++;
            if(maxRow[num]>ans.size())
            {
                ans.push_back({});
            }
            
            ans[maxRow[num] - 1].push_back(num);
        }
        
        return ans;
    }
};