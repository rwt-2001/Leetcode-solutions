class Solution {
public:
    map<string, int> mp;
    vector<int> dp;
    bool solve(string &s, int index)
    {
        if(index == s.size()) return true;
        if(dp[index] != -1) return dp[index];
        string str = "";
        for(int i = index; i < s.size(); i++)
        {
            str += s[i];
            if(mp[str])
            {
                bool canForm = solve(s, i + 1);
                if(canForm) return canForm;
            }
        }
        
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int> (s.size(), -1);
        for(auto word: wordDict)
        {
            mp[word]++;
        }
        
        
        return solve(s, 0);
    }
};