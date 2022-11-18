class Solution {
    int maxAnswer = INT_MIN;
public:
    void dfs_bob(int bob, int steps, vector<vector<int>> &graph, vector<int> &visitedBob, int &visited){
        visitedBob[bob] = steps;
        if(bob==0){
            visited = 1;
        }
    
        for(auto &node : graph[bob]){
            
            if(visitedBob[node] == -1){
                dfs_bob(node, steps+1, graph, visitedBob, visited);
                if(!visited){
                    visitedBob[node] = -1;
                }
            }
            if(visited) return;
            
        }
    }
    
    void dfs_alice(int alice, int steps, vector<vector<int>> &graph,vector<int> &visitedAlice, vector<int> &amount, int &ans,vector<int> &visitedBob){
        
        int isLeaf = 1;
        visitedAlice[alice] = steps;
        int curAmount = 0;
        if(visitedBob[alice]==-1 || visitedAlice[alice] < visitedBob[alice]){
            curAmount = amount[alice];
        }else if(visitedBob[alice] == visitedAlice[alice]){
            cout<<"Here equal ->> "<<alice<<endl;
            curAmount += amount[alice]/2;
        }
        ans += curAmount;
        cout<<alice<<" amount -> "<<ans<<endl;
        for(auto &node: graph[alice]){
            if(visitedAlice[node] == -1){
                isLeaf = 0;
                dfs_alice(node, steps+1, graph, visitedAlice, amount, ans, visitedBob);
                
            }
        }
        
        if(isLeaf){
            maxAnswer = max(ans, maxAnswer);
        }
        ans -= curAmount;
        visitedAlice[alice] = -1;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> graph (edges.size() + 1);
        for(auto &ev: edges)
        {
            graph[ev[0]].push_back(ev[1]);
            graph[ev[1]].push_back(ev[0]);
        }
        
        vector<int> visitedAlice(edges.size() + 1, -1);
        vector<int> visitedBob(edges.size() + 1, -1);
        
        int bob_reached = 0;
        dfs_bob(bob, 0, graph, visitedBob, bob_reached);
        int ans = 0;
        dfs_alice(0,0, graph,visitedAlice, amount, ans,visitedBob );
        return maxAnswer;
        
    }
};