class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        ans += s[0];
        int maxLen = 1;
        
        for(int i = 0;i<s.size();i++){
            int l = i;
            int r = i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            
            // cout<<l<<" "<<r<<" "<<(r-1) - (l+1) + 1<<endl;
            if( (r-1) - (l+1) + 1 > maxLen){
                   maxLen = (r-1) - (l+1) + 1 ;
                ans = s.substr(l+1, (r-1) - (l+1) + 1);
            }
            
            l = i;
            r = i+1;
            while(l>=0 && r<s.size() && s[r]==s[l]){
                l--;
                r++;
            }
            
            // cout<<l<<" "<<r<<" "<<(r-1) - (l+1) + 1<<endl;
             if( (r-1) - (l+1) + 1  > maxLen){
                  maxLen = (r-1) - (l+1) + 1 ;
                ans = s.substr(l+1, (r-1) - (l+1) + 1);
            }
        }
        
        return ans;
    }
};