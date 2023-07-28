class Solution {
public:
    int solve(vector<int> &nums, int i, int j)
    {
        if(i > j) return 0;
        if(i==j) return nums[i];
        
        int score = solve(nums, i+1, j-1);
        
        int mcscore = max(
            nums[i] + min(score, solve(nums, i+2, j)),
            nums[j] + min(score, solve(nums, i, j-2))
        );
            
        return mcscore;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int p1 = solve(nums,0, nums.size()-1);
        return p1>=(sum - p1);
    }
};