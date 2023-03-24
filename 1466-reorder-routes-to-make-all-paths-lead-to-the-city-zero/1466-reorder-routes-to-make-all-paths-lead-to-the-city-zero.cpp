class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n);
        vector<int> parent[n];
        vector<int> graph[n];
        
        for(auto con: connections)
        {
            int u = con[0];
            int v = con[1];
            graph[u].push_back(v);
            parent[v].push_back(u);
        }
        visited[0]++;
        int ans = 0;
        queue<int> q;
        q.push(0);
        
        while(q.size())
        {
            int sz = q.size();
            
            for(int i = 0; i < sz; i++)
            {
                int node =  q.front();
                cout<<node<<" ";
                q.pop();
                for(auto child: graph[node])
                {
                    if(visited[child]) continue;
                    ans++;
                    q.push(child);
                    visited[child]++;
                }
                for(auto child: parent[node])
                {
                    if(visited[child]) continue;
                    q.push(child);
                    visited[child]++;
                }  
            }
        }
        
        return ans;
        
    
    }
};