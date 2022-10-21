class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int ans = 1;
        
        int i = 0, j =0;
        int compute = 0;
        while(j<nums.size()){
        
            while(i < j && (compute & nums[j]) ){
                compute ^= nums[i++];
            }
            compute |= nums[j];
            ans = max(ans, j-i + 1);
            j++;
        }
        return ans;
    }
};