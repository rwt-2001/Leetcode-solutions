//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            vector<vector<int>> vec(N+1, vector<int> (32));
            
            for(int i = 0;i < Q;i++)
            {
                int l = U[i][0] - 1;
                int r = U[i][1] - 1;
                int num = U[i][2];
                
                
                for(int j = 0; j < 31; j++)
                {
                    int mask = 1 << j;
                    int bitHigh = num&mask;
                    
                    if(bitHigh)
                    {
                        vec[l][j]++;
                        vec[r+1][j]--;
                    }
                }
                
            }
            
        
            vector<int> Number(32);
            vector<int> ans(N);
            for(int i = 0;i < N;i++)
            {
                int cur_val = 0;
                for(int j = 0; j < 31;j++)
                {
                    Number[j] += vec[i][j];
                    int mask = 0;
                    if(Number[j]>0) mask = 1 << j;
                    cur_val = cur_val | mask;
                }
                ans[i] = cur_val;
                
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends