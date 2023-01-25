class Solution {
public:
    void dfs1(vector<int> &v, vector<int> &graph,int node, int dis)
    {
        if(v[node] > -1) return;
        v[node] = dis;
        if(graph[node] == -1) return;
        dfs1(v,graph, graph[node], dis + 1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        vector<int> v1(n, -1);
        dfs1(v1, edges, node1, 0);
        vector<int> v2(n, -1);
        dfs1(v2, edges, node2, 0);
        int minEl = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n;i++)
        {
            if(v1[i] > -1 && v2[i] > -1)
            {
                if(max(v1[i], v2[i]) < minEl)
                {
                    ans = i;
                    minEl = max(v1[i], v2[i]);
                }
            }
        }
        
        return ans;
        
    }
};