class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        if(s.size()!=t.size()) return false;
        for(auto c:s)
        {
            mp[c]++;
        }
        
        for(auto c: t)
        {
            mp[c]--;
        }
        
        
        for(auto val: mp)
        {
            if(val.second!=0) return false;
        }
        
        return true;
    }
};