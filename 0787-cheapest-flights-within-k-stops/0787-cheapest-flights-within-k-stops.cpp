class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        
        for(auto &way : flights)
        {
            int s = way[0];
            int d = way[1];
            int price = way[2];
            graph[s].push_back({d, price});
        }
        
        int ans = INT_MAX;
        int des_reached = 0;
        queue<pair<int,int>> q;
        vector<int> mp(n, INT_MAX);
        q.push({src, 0});
        k+=2;
        while(k-- && q.size())
        {
            int sz = q.size();
            for(int i = 0;i < sz;i++)
            {
                pair<int,int> cur_info = q.front();
                int cur_loc = cur_info.first;
                int cur_price = cur_info.second;
                // cout<<cur_loc<<endl;
                if(cur_loc == dst)
                {
                    ans = min(ans, cur_price);
                    des_reached = 1;
                }
                
                for(auto &next_loc : graph[cur_loc])
                {
                    int next = next_loc.first;
                    int next_price = next_loc.second;
                    int new_price = next_price + cur_price;
                    if(mp[next] < new_price) continue;
                    q.push({next, new_price});
                    mp[next]  = new_price;
                }
                q.pop();
            }
        }
        if(des_reached == 0) return -1;
        return ans;
        
    }
};