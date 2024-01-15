class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loser;
        for(int i = 0; i < matches.size(); i++)
        {
            
            if(loser.find(matches[i][0]) == loser.end()) loser[matches[i][0]] = 0;
            loser[matches[i][1]]++;
            
        }
        
        vector<vector<int>> ans(2);
        
        
        for(auto val: loser)
        {
            if(val.second == 0) ans[0].push_back(val.first);
            if(val.second == 1) ans[1].push_back(val.first);
        }
        
        return ans;
    }
};