class Solution {
public:
    int maxScore(string s) {
      
        int one = 0;
        int zero = 0;
        for(int i = 0; i < s.size();i++)
        {
            if(s[i]=='1') one++;
        }
        
        int ans = 0;
        for(int i = 0; i < s.size()-1; i++)
        {
            if(s[i]=='1') one--;
            else{
                zero++;
            }
            ans = max(ans, zero + one);
        }
        
        return ans;
    }
};