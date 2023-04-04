class Solution {
public:
    int partitionString(string s) {
        vector<int> mp(26);
        int i = 0;
        int ans = 0;
        while(i < s.size())
        {
            int c = s[i] - 'a';
            
            if(mp[c])
            {
                ans++;
                mp = vector<int>(26);
            }
            mp[c]++;
            
            i++;
        }
        
        return ans+1;
    }
};