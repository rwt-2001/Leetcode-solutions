class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int mis, rep;
        for(int i = 0;i<nums.size();i++){
            
            int index = abs(nums[i]) - 1;
            
            if(nums[index] < 0){
                
                rep = abs(index) + 1;
            }
            nums[abs(index)] = - abs(nums[abs(index)]);
        }
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > 0) mis = i+1;
        }
        
        
        vector<int> ans = {rep, mis};
        return ans;
        
    }
};