class Solution {
public:
    map<string, int> mp;
    vector<int> dp;
    int solve(string &s, int index)
    {
        if(index >= s.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int ans = 1 + solve(s, index + 1);
        string str = "";
        for(int i = index; i < s.size(); i++)
        {
            str+=s[i];
            
            if(mp[str])
            {
                ans = min(ans, solve(s, i+1));
            }
        }
        
        return dp[index] = ans;
    }
    int minExtraChar(string s, vector<string>& words) {
        
        dp = vector<int> (s.size(), -1);
        for(auto &word : words)
        {
            mp[word]++;
        }
        
        return solve(s, 0);
    }
};