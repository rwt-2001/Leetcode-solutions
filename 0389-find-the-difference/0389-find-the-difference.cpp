class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> mp(26);
        
        for(int i = 0; i < t.size(); i++)
        {
            mp[t[i] - 'a']++;
            if(i < s.size())
            {
                mp[s[i] - 'a']--;
            }
        }
        char ans;
     
        for(int i = 0; i < 26;i++)
        {
            if(mp[i])
            {
                ans = 'a' + i;
            }
        }
        return ans;
    }
};