class Solution {
    vector<vector<int>> dp;
public:
    
    int solve(vector<int> &j, int day, int index)
    {
        if(day == 0)
        {
            if(index == j.size())
            {
                return 0;
            }else{
                return 1e7;
            }
        }
        if(index == j.size()) return 1e7;
        if(dp[index][day] != -1) return dp[index][day];
        int ans = INT_MAX;
        int maxEl = INT_MIN;
        for(int i = index; i < j.size(); i++)
        {
            
            maxEl = max(j[i], maxEl);
            ans = min(ans, maxEl + solve(j, day - 1, i+1));
            
        }
        
        return dp[index][day]= ans;
    }
    int minDifficulty(vector<int>& job, int d) {
        dp = vector<vector<int>> (job.size(), vector<int>(d + 1, -1));
        int ans = solve(job, d, 0);
        return ans > 1e7 ? -1 : ans;
    }
};

