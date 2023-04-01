class Solution {
public:
    int solve(int day, int index, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        if(index == days.size()) return 0;
        
        if(day >= days[index])
            return solve(day, index+1, days, costs, dp);
        
        
        if(dp[index] != -1) return dp[index];
        int day1 = costs[0] + solve(days[index], index+1, days, costs, dp);
        int day7 = costs[1] + solve(days[index] + 6, index+1, days, costs, dp);
        int day30 = costs[2] + solve(days[index] + 29, index+1, days, costs, dp);
        return dp[index] = min({day1, day7, day30});
    
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(-1, 0, days, costs, dp);
    }
};