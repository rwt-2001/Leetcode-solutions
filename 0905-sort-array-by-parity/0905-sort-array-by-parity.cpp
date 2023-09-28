class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i = 0, j = nums.size() - 1;
        
        while(i < j)
        {
           
           if(nums[i]&1)
           {
               swap(nums[i], nums[j]);
               j--;
           }else{
               i++;
           }
            
        }
        
        return nums;
    }
};


// 1 3 2 1 6 5 4 
    
// 4  1