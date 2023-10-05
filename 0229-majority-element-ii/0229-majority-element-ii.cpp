class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = floor(nums.size() / 3);
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int curNum = nums[i];
            
            
            int j = i + 1;
            while(j < nums.size() && nums[j] == curNum){
                j++;
            }
            if( j - i > n) ans.push_back(curNum);
            i = j - 1;
        }
        return ans;
    }
};