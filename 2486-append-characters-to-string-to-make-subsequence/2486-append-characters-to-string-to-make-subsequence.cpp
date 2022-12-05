class Solution {
public:
    int appendCharacters(string s, string t) {
        int p = 0, q = 0;
        
        while(q < t.size() && p < s.size()){
            if(s[p] == t[q])q++;
            p++;
        }
        
        return ( q==t.size()) ? 0 : t.size()-q ; 
    }
};