class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        int ones = 0;
        for(int i = 31; i >= 0; i--)        
        {
            if((1<<i)&n) ones++;
            if(ones > 1) return false;
        }
        
        return ones == 1;
    }
};