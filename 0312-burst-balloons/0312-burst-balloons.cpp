class Solution {
public:
    int f(vector<int> &a, int start, int end, vector<vector<int>> &dp)
        {
            if(dp[start][end] != -1) return dp[start][end];
            
            int ans = 0;
            for(int i = start; i <= end;i++)
            {
                int cur = a[start-1] * a[i] * a[end+1];
                int left = f(a, start , i - 1, dp);
                int right = f(a, i+1, end, dp);
                
                ans = max(ans, cur+left+right);
            }
            
            return dp[start][end] = ans;
        }
        int maxCoins( vector <int> &a)
        {
                    // write your code here
                    vector<vector<int>> dp(a.size()+2, vector<int>(a.size()+2, -1));
                    a.insert(a.begin(),1);
                    a.push_back(1);

                    return f(a,1,a.size()-2,dp);

        }
};