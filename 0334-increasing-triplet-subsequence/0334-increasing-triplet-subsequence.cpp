class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, mid = INT_MAX;
        for(int &cur_num : nums){
            if(cur_num<=small) small = cur_num;
            else if(cur_num<=mid) mid = cur_num;
            else return true;
        }
        return false;
    }
};