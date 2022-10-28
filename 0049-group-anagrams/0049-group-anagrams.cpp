class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        
        for(auto &word : strs){
            
            mp[sortStr(word)].push_back(word);
            
        }
        vector<vector<string>> ans;
        for(auto &val : mp) ans.push_back(val.second);
        
        return ans;
    }
    
    
    string sortStr(string &s){
        vector<int> mp(26);
        
        for(auto &c : s){
            mp[c-'a']++;
        }
        string res = "";
        
        for(int i = 0;i < 26;i++){
            
            int freq = mp[i];
            
            while(freq--){
                res+= ('a' + i);
            }
            
            
        }
        return res;
    }
};