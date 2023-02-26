class Solution {
public:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        
        if(i == word1.size() && j == word2.size()) return 0;
        if(i==word1.size() || j == word2.size())
        {
            if(i == word1.size()) return word2.size() - j;
            else if(j == word2.size()) return word1.size() - i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j])
        {
            return dp[i][j] = f(i + 1, j + 1, word1, word2, dp);
        }
        
        
        int ins = 1 + f(i, j + 1,word1, word2, dp);
        int del = 1 + f(i+1, j, word1,word2, dp);
        int rep = 1 + f(i + 1, j + 1, word1, word2, dp);
        
        return dp[i][j] = min({ins, del, rep});
    }
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        return f(0,0,word1,word2, dp);
    }
};