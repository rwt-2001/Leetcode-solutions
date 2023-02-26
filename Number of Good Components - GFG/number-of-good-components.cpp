//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    pair<int,int> dfs(vector<vector<int>> &graph, vector<int> &visited, int cur_node){
        visited[cur_node] = 1;
        int nCnt = 1;
        int minEdge = graph[cur_node].size();
        
        for(auto adjN : graph[cur_node])
        {
            if(visited[adjN]) continue;
            auto rp = dfs(graph, visited, adjN);
            int tnodes = rp.first;
            int minEd = rp.second;
            nCnt+=tnodes;
            minEdge = min(minEdge, minEd);
        }
        
        return {nCnt, minEdge};
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& graph) {
        // code here
        vector<int> visited(V + 1, 0);
        int ans = 0;
        for(int i = 1; i < graph.size(); i++)
        {
            if(visited[i]) continue;
            auto rp = dfs(graph, visited, i);
            int tnodes = rp.first;
            int minEd = rp.second;
            if(tnodes == minEd + 1) ans++;
            visited[i] = 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends