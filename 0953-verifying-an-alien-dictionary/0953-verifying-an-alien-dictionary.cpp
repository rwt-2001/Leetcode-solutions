class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(26, 0);
        
        for(int i = 0; i < order.size(); i++)
        {
            mp[order[i] - 'a'] = i;
        }
        
        
        for(int i = 0; i < words.size() - 1; i++)
        {
            int flag = 1;
            for(int j = 0; j < words[i].size() && j < words[i+1].size() ;j++)
            {
                if(mp[words[i][j]-'a'] > mp[words[i+1][j] - 'a']) return false;
                else if(mp[words[i][j]-'a'] < mp[words[i+1][j] - 'a']){
                    flag = 0;
                    break;
                }
            }
            if(flag && words[i].size() > words[i+1].size()) return false;
        }
        
        return true;
    }
};