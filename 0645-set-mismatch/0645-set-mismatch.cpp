class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            
            if(nums[index] < 0){
                ans.push_back(index+1);
            }else{
                nums[index]=-1*nums[index];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) 
            {
                ans.push_back(i + 1);
                break;
            }
        }
        return ans;
    }
};