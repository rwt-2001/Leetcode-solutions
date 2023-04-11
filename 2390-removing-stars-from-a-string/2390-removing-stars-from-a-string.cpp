class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int rem = 0;
        
        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i]=='*')
            {
                rem++;
                continue;
            }
            
            if(rem > 0)
            {
                rem--;
            }else{
                ans += s[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};