class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n-1;
        int j = n-1;
        string ans = "";
        
        while(j>=0){
            if(s[j]!=' '){
                i = j;
                while(i>=0 && s[i]!=' '){
                    i--;
                }
                if(i<0 || (i>=0 && s[i]==' ')) i++;
                int temp = i;
                
                while(i<=j){
                    ans+=s[i];
                    i++;
                }
                ans += ' ';
                j = temp-1;
            }
            
            j--;
        }
        ans.erase(ans.size()-1, 1);
        return ans;
        
    }
};