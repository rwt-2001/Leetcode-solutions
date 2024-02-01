class Solution {
    
public:
   
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        bool flag = true;
        for(int i = 0; i<nums.size(); i+=3)
        {
            if(abs(nums[i] - nums[i + 2]) <= k)
            {
                vector<int> temp;
                
                for(int j = i; j < i+3;j++)
                {
                    temp.push_back(nums[j]);
                }
                ans.push_back(temp);
            }else{
                flag = false;
                break;
            }
        }
        
        if(!flag) return {};
        return ans;
    }
};