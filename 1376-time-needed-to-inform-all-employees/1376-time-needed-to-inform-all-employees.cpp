class Solution {
public:
    int dfs(vector<vector<int>> &g,vector<int>& informTime, int node)
    {
        int curTime = informTime[node];
        int ans = 0;
        
        for(auto child : g[node])
        {
            ans = max(ans, curTime + dfs(g, informTime, child) );
        }
        
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        
        
       for(int i = 0; i < n; i++)
       {
          
          if(i == headID) continue; 
           
          graph[manager[i]].push_back(i);
       }
    

        return dfs(graph, informTime, headID);
    }
};