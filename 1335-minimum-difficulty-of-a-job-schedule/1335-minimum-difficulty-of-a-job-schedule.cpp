class Solution {
public:
    int solve(vector<int> &j, int index, int curMax, int d, vector<vector<vector<int>>> &dp){
        // cout<<index<<" "<<index<<endl;
        
        if(index==j.size()) return 300000;
        
        if(d==1){
            return *max_element(j.begin() + index, j.end());
        }
        
        
        
        if(dp[index][d][curMax] != -1) return dp[index][d][curMax];
        curMax = max(curMax, j[index]);
        
        int pick = curMax + solve(j, index+1, 0, d-1, dp);
        
        int notPick = solve(j, index+1, curMax, d, dp);
        
        return dp[index][d][curMax] = min(pick, notPick);
        
        
    }
    int minDifficulty(vector<int>& j, int d) {
        if(d > j.size()) return -1;
        vector<vector<vector<int>>> dp(j.size(), vector<vector<int>> (d+1, vector<int> ( 1002, -1)));
        return solve(j, 0, 0, d, dp);
    }
    
};