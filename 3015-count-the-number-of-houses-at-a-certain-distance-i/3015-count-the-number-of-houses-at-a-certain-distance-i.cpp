class Solution {
    vector<int> ans;
    
public:
    int solve(vector<vector<int>> &graph, int u, int v){

        
        queue<int> q;
        q.push(u);
        
        int distance = 0;
        vector<int> mp(graph.size(), 1e4);
        while(q.size()){
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                auto topE = q.front();
                q.pop();
                if(topE == v){
                    return distance;
                }
                for(auto val: graph[topE]){
                    if(mp[val] <= distance+1) continue;
                    mp[val] = distance+1;
                    q.push(val);
                }
                
                
            }
            distance++;
        }
        
        return 1;
        
    }
    vector<int> countOfPairs(int n, int x, int y) {

        ans = vector<int> (n, 0);
        vector<vector<int>> graph(n);
        
        
        
        for(int i = 0; i < n -1; i++){
            graph[i].push_back(i + 1);
            graph[i+1].push_back(i);
        }
        
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++){
                ans[solve(graph,i,j) - 1] += 2;
            }
        }
        

        return ans;
    }
};