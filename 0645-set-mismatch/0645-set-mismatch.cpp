class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int mis=0, rep = 0;
        for(int i = 0;i<nums.size();i++){
            mis = mis ^ (i+1) ^ abs(nums[i]);
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0){
                rep = abs(index) + 1;
            }
            nums[abs(index)] = - abs(nums[abs(index)]);
        }
        

        mis = mis ^ rep;
        
        vector<int> ans = {rep, mis};
        return ans;
        
    }
};