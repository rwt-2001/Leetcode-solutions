class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        
        string res = s;
        for(int i = 0;i < s.size();i++){
            s  = s.substr(1) + s[0];
            res = min(res, s);
        }
        return res;
    }
};