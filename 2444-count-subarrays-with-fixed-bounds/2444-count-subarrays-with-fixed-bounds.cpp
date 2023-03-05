class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int indexMin = -1;
        int indexMax = -1;
        int start = 0;
        long long res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == minK) indexMin = i;
            if(nums[i] == maxK) indexMax = i;
            
            if(nums[i] > maxK || nums[i] < minK)
            {
                  start = i+1;
                  indexMin = -1;
                  indexMax = -1;
            }
            if(indexMin != -1 && indexMax != -1)
            {
                res+= (min(indexMax, indexMin) - start + 1);
            }
            
        }
        
        return res;
    }
};

//1,3,5,2,7,5

//1,3,5 -> 1
//1,3,5, 2 -> 2

