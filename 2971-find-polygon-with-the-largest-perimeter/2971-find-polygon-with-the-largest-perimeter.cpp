class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;
        long long sum = 0;
        sort(nums.begin(), nums.end());
    
        for(int i = 0; i < nums.size(); i++)
        {
            sum += 1l*nums[i];
            
            if(i > 1){
                if(nums[i] < sum - nums[i]){
                    ans = sum;
                }
            }
        }
        
        return ans;
    }
};