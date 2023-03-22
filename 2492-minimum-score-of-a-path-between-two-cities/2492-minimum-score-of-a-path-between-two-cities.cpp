class Solution {
public:
    void dfs(vector<int> &visited,vector<vector<pair<int,int>>> &graph, int parent, int &minScore)
    {
        if(visited[parent]) return;
        visited[parent] = 1;
        for(auto child: graph[parent])
        {
            minScore = min(minScore, child.second);
            dfs(visited, graph, child.first, minScore);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        
        int minScore = INT_MAX;
        
        for(auto entry : roads)
        {
            int n1 = entry[0] - 1;
            int n2 = entry[1] - 1;
            int w = entry[2];
            
            graph[n1].push_back({n2, w});
            graph[n2].push_back({n1, w});
        }
        vector<int> visited(n);
        dfs(visited, graph, 0, minScore);
        
        return minScore;
        
    }
};