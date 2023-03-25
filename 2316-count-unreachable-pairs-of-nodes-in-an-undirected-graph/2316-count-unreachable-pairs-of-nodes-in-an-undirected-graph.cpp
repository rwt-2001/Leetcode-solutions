class Solution {
public:
    int dfs(vector<int> &v, vector<vector<int>> &graph, int node)
    {
        v[node] = 1;
        int count = 0;
        for(auto child : graph[node])
        {
            if(v[child])continue;
            count+= dfs(v, graph, child);
        }
        return count + 1;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> v(n);
        vector<vector<int>> graph(n);

        
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> comp;
        
        for(int i = 0; i < n; i++)
        {
            if(v[i]) continue;
            comp.push_back(dfs(v, graph, i));
        }
        
        long long res = 0;
        long long cnt = n;
        
        for(auto nodes : comp)
        {
            res += (cnt - nodes) * nodes;
            cnt -= nodes;
        }
        
        
        return res;
        
    }
};