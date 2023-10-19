class Solution {
    vector<int> dp;
public:
    int f(vector<vector<int>> &graph, int curNode, vector<int> &time)
    {
        
        if(dp[curNode]!=-1) return dp[curNode];
        int ans = 0; 
        for(auto node: graph[curNode])
        {
            ans = max(ans, f(graph, node, time));
        }
        
        return dp[curNode] = ans + time[curNode - 1];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n+1);
        
        dp = vector<int> (n+1, -1);
        
        for(auto rel: relations)
        {
            int u = rel[0];
            int v = rel[1];
            graph[u].push_back(v);
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dp[i] == -1)
            {
                ans = max(ans, f(graph, i, time));
            }
        }
        
        return ans;
        
        
    }
};