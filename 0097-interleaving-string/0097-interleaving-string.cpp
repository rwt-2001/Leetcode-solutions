class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if(i==s1.size() && j==s2.size())
        {
            if(k==s3.size()) return true;
            else return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool canForm = false;
        if(i < s1.size() && s3[k] == s1[i]){
            if(solve(s1, s2, s3, i+1, j, k + 1)) return true;
        }
        
        if(j < s2.size() && s3[k] == s2[j])
        {
            if(solve(s1, s2, s3, i, j + 1, k+1)) return true;
        }
        dp[i][j] = 0;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp = vector<vector<int>> (s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(s1, s2, s3, 0, 0, 0);
    }
};