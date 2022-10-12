class Solution {
public:
    int tri(int a, int b, int c){
       return a < b + c; 
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        n--;
        
        while(n>=2){
            if(tri(nums[n],nums[n-1], nums[n-2])) return nums[n] + nums[n-1] +nums[n-2];
            n--;
        }
        
        return 0;
    }
};