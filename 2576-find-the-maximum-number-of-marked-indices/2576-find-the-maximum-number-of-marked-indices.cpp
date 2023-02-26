class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() / 2;
        
        int ans= 0;
        while(i < nums.size()/2 && j < nums.size())
        {
            if(nums[i] * 2 <= nums[j]){
                i++;
                j++;
                ans+=2;
            }
            else{
                j++;
            }
        }
        
        return ans;
    }
};