class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for(auto c: word1)
        {
            mp1[c-'a']++;
        }
        
        
        for(auto c: word2)
        {
            mp2[c-'a']++;
        }
        map<int,int> mpp;
        
        for(int i = 0; i < 26; i++)
        {
            if((mp1[i] && !mp2[i])  || (!mp1[i] && mp2[i])) return false;
            mpp[mp1[i]]++;
            mpp[mp2[i]]--;
        }
        for(auto val: mpp)
        {
            if(val.second!=0) return false;
        }
        return true;
    }
};