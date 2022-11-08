class Solution {
public:
    string makeGood(string s) {
       
        
        string ans = "";
        int i;
        for(i = 0;i < s.size() - 1;i++){
            if(s[i] - 'a' == s[i+1] - 'A' || s[i] - 'A' == s[i+1] - 'a') i+=1;
            else if(ans != "" && (ans[ans.size()-1] - 'A' == s[i] - 'a'|| ans[ans.size()-1] - 'a' == s[i] - 'A') ){
                ans = ans.erase(ans.size()-1,1);
            }else{
                ans += s[i];
            }
        }
        if(i==s.size() - 1){
         if(ans != "" && (ans[ans.size()-1] - 'A' == s[i] - 'a'|| ans[ans.size()-1] - 'a' == s[i] - 'A') ){
                ans = ans.erase(ans.size()-1,1);
        }else{
                ans += s[i];
        }
        }
        
        return ans;
        
    }
};