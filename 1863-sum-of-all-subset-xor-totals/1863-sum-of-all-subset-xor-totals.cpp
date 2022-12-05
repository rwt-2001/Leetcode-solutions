class Solution {
    int sum = 0;
public:
    void dfs(int index, vector<int> &nums, int &xorr){
        if(index == nums.size()){
            sum += xorr;
            return;
        }
        //PICK
        xorr^=nums[index];
        dfs(index + 1, nums, xorr);
        //NOTPICK
        xorr^=nums[index];
        dfs(index + 1, nums, xorr);
    }
    int subsetXORSum(vector<int>& nums) {
        int xorr = 0;
        dfs(0, nums, xorr);
        return sum;
    }
};