class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        
        
        for(auto &word : strs){
            map<char,int> tempMp;
            for(auto &c : word){
                tempMp[c]++;
            }
            
            mp[tempMp].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto &val : mp){
            ans.push_back(val.second);
        }
        return ans;
    }
};