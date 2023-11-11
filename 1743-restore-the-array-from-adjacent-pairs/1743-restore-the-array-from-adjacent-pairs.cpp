class Solution {
    vector<int> ans;
public:
    
    
    vector<int> restoreArray(vector<vector<int>>& arr) {
        map<int,vector<int>> graph;
        for(auto &num: arr)
        {
            graph[num[0]].push_back(num[1]);
            graph[num[1]].push_back(num[0]);
        }
        for(auto val: graph)
        {
            if(val.second.size() == 1){
                ans.push_back(val.first);
                break;
            }
        }
        
        int prev_node = -1;
        int cur_node = ans[0];
        
        while(ans.size() != graph.size())
        {
            
            for(auto &next: graph[cur_node])
            {
                if(next != prev_node)
                {
                    prev_node = cur_node;
                    cur_node = next;
                    ans.push_back(cur_node);
                    break;
                }
            }
        }
        
        return ans;
        
        
        
        
    }
};