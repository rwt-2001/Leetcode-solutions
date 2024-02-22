class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>>arr(n+1,{0,0});
        
        for(auto &val: trust)
        {
            arr[val[0]].second++;
            arr[val[1]].first++;
        }
        
        for(int i = 1; i < arr.size(); i++){
            pair<int,int> val = arr[i];
            
            if(val.first == n-1 && val.second == 0) return i;
        }
        return -1;
    }
};