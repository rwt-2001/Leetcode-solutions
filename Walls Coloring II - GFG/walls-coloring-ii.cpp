//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        
        vector<vector<int>> dp(costs.size()+1, vector<int> (costs[0].size()+1, INT_MAX));
        
        for(int j = 0; j < costs[0].size(); j++)
        {
            dp[0][j] = costs[0][j];
        }
        
        for(int i = 1; i < costs.size(); i++)
        {
            int min1 = 1e7;
            int min2 = 1e7;
            int minIndex = -1;
            
            for(int j = 0; j < costs[0].size(); j++)
            {
                if(dp[i-1][j] <= min1)
                {
                    min2 = min1;
                    min1 = dp[i-1][j];
                    minIndex = j;
                }else if(dp[i-1][j] < min2)
                {
                    min2 = dp[i-1][j];
                }
            }
            for(int j = 0; j < costs[0].size(); j++)
            {
                if(minIndex==j)
                {
                    dp[i][j] = costs[i][j] + min2;
                }else{
                    dp[i][j] = costs[i][j] + min1;
                }
            }
        }
        
        
        int ans = *min_element(dp[costs.size()-1].begin(), dp[costs.size()-1].end());
        return ans >= 1e7 ? -1 : ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends