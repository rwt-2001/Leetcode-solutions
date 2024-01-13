class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp(26,0);
        
        for(auto c: s)
        {
            mp[c-'a']++;
        }
        
        for(auto c: t)
        {
            mp[c-'a']--;
        }
        
        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            if(mp[i] > 0) ans+= mp[i];
        }
        
        return ans;
        
    }
};


    