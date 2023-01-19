class UF{
    int *parent;
    int *rank;
    
    public:
    
    UF (int size)
    {
        parent = new int[size];
        rank = new int[size];
        for(int i = 0;i<size;i++)
        {
            parent[i] = i;
        }
        for(int i = 0;i<size;i++)
        {
            rank[i] = 0;
        }
    }
    int find_parent(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = find_parent(parent[node]);
    }
    void connect(int p, int q)
    {
        int i = find_parent(p), j = find_parent(q);
        if (i == j)
            return;
        if (rank[i] < rank[j])
        {
            parent[i] = j;
        }
        else
        {
            parent[j] = i;
            if (rank[i] == rank[j])
                rank[j]++;
        }
    }

    
};
class Solution {
public:
    int ans = 0;
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        map<int,vector<int>> valueMap;
        for (int i = 0;i < vals.size(); i++)
        {
            valueMap[vals[i]].push_back(i);
        }
        
        int nodes = vals.size();
        
        
        vector<vector<int>> graph(nodes);
        
        for(auto e : edges)
        {
            int u = e[0];
            int v  = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int ans = 0;
        UF uf(nodes);
        
        for(auto &val : valueMap)
        {
            // cout<<val.first<<"->";
            for( auto &node : val.second)
            {
                for(auto &adjnode : graph[node])
                {
                    
                    if(vals[adjnode] <= vals[node])
                        uf.connect(node, adjnode);
                    
                }
                
            }
            map<int,int> count;
                
            for( auto &node : val.second)
            {
                int parent = uf.find_parent(node);
                count[parent]++;
                ans+= count[parent];
            }
            // cout<<endl;
        }
        
        
        return ans;
    }
};
