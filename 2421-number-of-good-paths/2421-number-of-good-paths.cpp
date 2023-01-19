class UF
{
    int *parent;
    int *rank;
    
    public:
    
    UF(int size)
    {
        parent = new int[size];
        rank = new int[size];
        iota(parent, parent + size,0);
        for(int i = 0; i< size;i++)
            rank[i] = 0;
    }
    
    int find(int node)
    {
        if(node == parent[node]) return node;
        return parent[node]  = find(parent[node]);
    }
    
    void connect(int u, int v){
        
        u = find(u);
        v = find(v);
        
        if(u == v) return;
        
        if(rank[u] > rank[v])
        {
            parent[v] = u;
        }else if(rank[u] < rank[v]){
            parent[u] = v;
        }else{
            parent[v] = u;
            rank[v]++;
        }
        
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        map<int,vector<int>> valueIndex;
        int nodes = vals.size();
        for(int i = 0;i < nodes; i++)
        {
            valueIndex[vals[i]].push_back(i);
        }
        
        vector<vector<int>> graph(nodes);
        
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int res = 0;
        UF uf(nodes);
        
        for(auto &val : valueIndex)
        {
            for(auto &node : val.second)
            {
                for(auto &adjNode : graph[node])
                {
                    if(vals[adjNode] <= vals[node])
                    {
                        uf.connect(adjNode, node);
                    }
                }
            }
            
            map<int,int> good_path;
            for(auto &node : val.second)
            {
                
                int parent = uf.find(node);
                good_path[parent]++;
                res+=good_path[parent];
            }
            
        }
        
        return res;
    }
};