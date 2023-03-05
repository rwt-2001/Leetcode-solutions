class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mp;
        int n = arr.size() - 1;
        for(int i = 0; i <= n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int> visited(arr.size(), 0);
        map<int,int> dp;
        queue<int> q;
        q.push(0);
        int ans = 0;
        
        while(q.size())
        {
            
            int sz = q.size();
            
            for(int i = 0; i < sz; i++)
            {
                int cur_index = q.front();
                if(cur_index==n) return ans;
                q.pop();
                int cur_val = arr[cur_index];
                visited[cur_index] = 1;
                
                for(auto index: mp[cur_val])
                {
                    
                    if(visited[index]) continue;
                    visited[index] = 1;
                    q.push(index);
                }
                mp.erase(cur_val);
                if(cur_index - 1 >= 0 && cur_index - 1 <= n)
                {
                    if(!visited[cur_index - 1]) q.push(cur_index-1);
                    visited[cur_index-1] = 1;
                }
                if(cur_index + 1 >= 0 && cur_index + 1 <= n)
                {
                    if(!visited[cur_index + 1]) q.push(cur_index+1);
                    visited[cur_index+1] = 1;
                }
                
                
            }
            ans++;
        }
        
        return -1;
        
    }
};