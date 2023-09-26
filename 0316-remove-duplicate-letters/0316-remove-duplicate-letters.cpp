class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> mp(26);
        vector<int> visited(26,0);
        
        
        for(auto c: s)mp[c - 'a']++;
        
        string ans="";
        for(int i = 0; i < s.size();i++)
        {
            if(!visited[s[i] - 'a'])
            {
                while(ans.size() && (s[i] < ans[ans.size() - 1])  && (mp[ans[ans.size() - 1] - 'a']>0) )
                {
                    visited[ans[ans.size() - 1] - 'a'] = 0;
                    ans.pop_back();
                }
                ans+=s[i];
                visited[s[i] - 'a'] = 1;
            }
            
            mp[s[i] - 'a']--; 
            
        }
        
        return ans;
    }
};


