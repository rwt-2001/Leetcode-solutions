//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> ans(N, INT_MAX);
        ans[0] = 0;
        queue<pair<int,int>> q;
        vector<vector<pair<int,int>>> graph(N);
        
        for(auto &e : edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
        }
        
        q.push({0,0});
        while(! q.empty())
        {
            int v = q.front().first;
            int d = q.front().second;
            q.pop();
            for(auto nn: graph[v])
            {
                int uu = nn.first;
                int dd = nn.second;
                if(dd + d < ans[uu])
                {
                    ans[uu] = dd+d;
                    q.push({uu, dd+d});
                }
            }
        }
        for(auto &d: ans)
        {
            if(d==INT_MAX) d = -1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends