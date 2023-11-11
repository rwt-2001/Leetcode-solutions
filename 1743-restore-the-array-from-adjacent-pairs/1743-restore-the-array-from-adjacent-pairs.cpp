class Solution {
    vector<int> ans;
public:
    
    void dfs(int node, map<int, vector<int>> &graph, map<int,int> &visited)
    {
        if(visited[node] == 1) return;
        ans.push_back(node);
        visited[node] = 1;
        for(auto child: graph[node])
        {
            dfs(child, graph, visited);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& arr) {
        map<int,vector<int>> graph;
        map<int,int> cnt;
        for(auto &num: arr)
        {
            cnt[num[0]]++;
            cnt[num[1]]++;
            graph[num[0]].push_back(num[1]);
            graph[num[1]].push_back(num[0]);
        }
        for(auto val: cnt)
        {
            if(val.second == 1){
                ans.push_back(val.first);
                break;
            }
        }
        map<int,int> visited;
        visited[ans[0]] = 1;
        for(auto child: graph[ans[0]])
        {
            dfs(child, graph, visited);
        }
        
        return ans;
        
        
        
        
    }
};