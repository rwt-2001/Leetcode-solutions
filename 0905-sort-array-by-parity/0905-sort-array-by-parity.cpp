class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i = 0, j = nums.size() - 1;
        
        while(i < j)
        {
           
            if(((nums[j]&1)==0) || (nums[i]&1))
            {
                swap(nums[i], nums[j]);
            }
            if(nums[i]%2==0) i++;
            if(nums[j]&1) j--;
            
            
        }
        
        return nums;
    }
};


// 1 3 2 1 6 5 4 
    
// 4  1