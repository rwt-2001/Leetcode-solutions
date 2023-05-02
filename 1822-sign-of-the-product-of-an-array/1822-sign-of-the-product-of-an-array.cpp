class Solution {
public:
    int arraySign(vector<int>& nums) {
        int m = 0;
        for(auto n : nums)
        {
            if(n==0) return 0;
            if(n < 0) m++;
        }
        
        return (m&1) ? -1 : 1;
    }
};