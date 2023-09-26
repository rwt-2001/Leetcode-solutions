class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> mp;
        map<char,int> visited;
        
        
        for(auto c: s)mp[c]++;
        
        string ans="";
        for(int i = 0; i < s.size();i++)
        {
            while(ans.size() && (s[i] < ans[ans.size() - 1]) && !visited[s[i]] && (mp[ans[ans.size() - 1]]>0) )
            {
                visited[ans[ans.size() - 1]] = 0;
                ans.pop_back();
            }
            
            if(!visited[s[i]])
            {
                ans+=s[i];
                visited[s[i]] = 1;
            }
            
            mp[s[i]]--; 
            
        }
        
        return ans;
    }
};


