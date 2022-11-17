class Solution {
public:

    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 32;
        
        for(auto &num : nums)
            xorr ^= num;
        
        int bitPos = log2(xorr&(~(xorr-1)));
        
        int a = 0, b = 0;
        for(auto &num : nums){
            if(num&(1<<bitPos)){
                a ^= num;
            }else{
                b ^= num;
            } 
            
        }
        return {a,b};
    }
};