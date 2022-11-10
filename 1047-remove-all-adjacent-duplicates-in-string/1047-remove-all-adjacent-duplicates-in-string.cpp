class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stk;
        int n = s.size();
        int i = 0;
        while(i<n){
            if(stk.size()!=0 && stk.back() == s[i]){
                stk.pop_back();
            }else{
                stk.push_back(s[i]);
            }
            i++;
        }
        
        string ans = "";
        for(int i = 0;i<stk.size();i++)
            ans+=stk[i];
        return ans;
    }
};