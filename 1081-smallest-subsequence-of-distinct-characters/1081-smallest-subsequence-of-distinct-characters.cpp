class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> mp(26,0);
        vector<int> visited(26, 0);
        
        
        
        for(auto c: s)
        {
            mp[c-'a']++;
        }
        
        string ans = "";      
        for(int i = 0; i < s.size(); i++)
        {
            int len = ans.size();
            if(visited[s[i] - 'a'] == 0)
            {
                while(len > 0 && ans[len - 1] > s[i] && mp[ans[len - 1] - 'a'])
                {
                    visited[ans[len-1] - 'a'] = 0;
                    ans.pop_back();
                    len--;
                }
                
                ans += s[i];
                visited[s[i] - 'a'] = 1;
            }
            
            mp[s[i] - 'a']--;
        }
        
        return ans;
    }
};