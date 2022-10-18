class Solution {
public:
    int getSum(int a, int b) {
        
        int ans = 0;
        
        int lastCarry = 0;
        
        for(int i = 0;i<=31;i++){
            
            int bitA = (a>>i) & 1; 
            int bitB = (b>>i) & 1;

            
            ans = ans | ((bitA ^ bitB ^ lastCarry)<<i) ;
            lastCarry = (bitA&bitB) | ((bitA | bitB) & lastCarry);
        }
        return ans;
    }
};