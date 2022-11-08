class Solution {
public:
    string makeGood(string s) {
        int p = -1;
        int i ;
        
        for(i = 0;i<s.size();i++){
            if(p != -1 && abs(s[i] - s[p]) == 32){
                p--;
            }else{
                s[++p] = s[i];
            }
        }
        
        return s.substr(0, p+1);
    }
};