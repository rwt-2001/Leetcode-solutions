class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> mp;
        map<int,int> mp1;
        for(auto &t: trust)
        {
            mp[t[1]]++;
            mp1[t[0]]++;
        }
        
        
        for(int i = 1; i <= n;i++)
        {
            if(mp1[i]==0 && mp[i]==n-1){
                return i;
            }
        }
        
        return -1;
    }
};