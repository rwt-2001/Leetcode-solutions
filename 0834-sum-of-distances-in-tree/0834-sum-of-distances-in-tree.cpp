class Solution {
public:
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        
        vector<vector<int>> graph(n);
        for(auto &v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        vector<int> below(n);
        
        auto dfs = [&](auto &self, int node, int level, int parent)->int{
                int ans = 0;
                for(auto child : graph[node]){
                    if(child == parent) continue;
                    ans += self(self, child, level + 1, node);
                }
             
            return level + ans;
        };


        
        auto find_nodes_below = [&](auto &self, int node, int parent)->int{
                int ans = 0;
                for(auto child : graph[node]){
                     if(child == parent) continue;
                    ans += self(self, child, node);
                }
                below[node] = ans;
                return ans + 1;
        };
        
        vector<int> ans_vector(n);
        
        auto dfs_ans = [&](auto &self, int parent, int node)->void{
            
                ans_vector[node] = ans_vector[parent] - below[node] + (n - below[node] - 2); 
            
                for(auto child : graph[node]){
                    if(child == parent) continue;
                    self(self,node, child);
                }
        };
        
        
        
    
       
        int rootCnt = dfs(dfs, 0, 0, -1);
        ans_vector[0] = rootCnt;
        // cout<<rootCnt<<" ";
        
        find_nodes_below(find_nodes_below, 0, -1);
        
        for(auto node: graph[0]) dfs_ans(dfs_ans, 0, node);
        
        // for(auto node : below) cout<<node<<" ";
        return ans_vector;
        
    }
};