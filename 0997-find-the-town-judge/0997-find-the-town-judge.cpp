class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> mp;
        for(auto &t: trust)
        {
            mp[t[1]]++;
            mp[t[0]]--;
        }
        
        
        for(int i = 1; i <= n;i++)
        {
            if(mp[i]==n-1){
                return i;
            }
        }
        
        return -1;
    }
};