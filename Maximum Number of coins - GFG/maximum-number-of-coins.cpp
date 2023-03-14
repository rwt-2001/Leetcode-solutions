//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
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
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                vector<vector<int>> dp(N+2, vector<int>(N+2, -1));
                a.insert(a.begin(),1);
                a.push_back(1);
                
                return f(a,1,N,dp);
                
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends