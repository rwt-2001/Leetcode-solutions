class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lastIndex = 0;
        int j;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) k--;
            
            if(k < 0 && nums[lastIndex++] == 0) k++;
            
        }
        
        return nums.size() -lastIndex;
    }
};