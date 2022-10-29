class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> plantGT;
        
        for(int i = 0;i<plantTime.size();i++){
            plantGT.push_back({growTime[i], plantTime[i]});
        }
        
        
        sort(plantGT.rbegin(), plantGT.rend());
        
        int maxTime = 0;
        int pt = 0;
        
        for(auto &gt: plantGT){
            
            pt += gt.second;
            int curGt = gt.first;
            maxTime = max(pt + curGt, maxTime);
        
        }
        
        return maxTime;
        
    }
};