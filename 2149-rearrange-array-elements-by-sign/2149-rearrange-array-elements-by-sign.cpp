class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int o = 0;
        int e = 1;
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if(num < 0){
                ans[e] = num;
                e+=2;
            }else{
                ans[o] = num;
                o+=2;
            }
        }
        return ans;
    }
};