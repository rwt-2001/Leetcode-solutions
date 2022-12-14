class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sz = nums.size();
        int r1 = 0, r2 = 0;
        for(int i = 0;i<sz;i++){
            int temp = max(r1 + nums[i], r2);
            r1 = r2;
            r2 = temp;
        }
        
        return r2;
    }
};