class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26);
        vector<int> visited(26);
        string ans = "";
        int i = 0;
        for(auto &c : s) freq[c-'a']++;
        
        for(auto &c : s){
           // cout<<"HERE"<<"---"<<c<<"---"<<ans<<endl;
            while(ans.size() != 0 && ans.back() >= c && freq[ans.back()-'a']>0 &&  visited[c-'a'] == 0){
                
                visited[ans.back()-'a'] = 0;
                
                ans.pop_back();
                // cout<<i++<<endl;
            }
            if(visited[c-'a'] == 0){
                 ans.push_back(c);
                 visited[c-'a'] = 1;
                 
             }
                freq[c-'a']--;
            
        }
        
        return ans;
        
    }
};