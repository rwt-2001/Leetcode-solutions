class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(256);
        for(auto &c : t){
            mp[c]++;
        }
        int count = t.size();
        int i = 0;
        
        int start = 0, end = INT_MAX;
        for(int j = 0;j<s.size();j++){
            if(mp[s[j]] > 0) count--;
            mp[s[j]]--;
            
            while(count == 0){
                if(end - start > j - i){
                    start = i;
                    end = j;
                }
                
                if(mp[s[i]] == 0){
                    count++;
                }
                mp[s[i]]++;
                i++;
            }
            
        }
        // cout<<start<<" "<<end;
        
        return end==INT_MAX ? "" : s.substr(start, end - start + 1);
        
        
        
    }
};