class UnionFind
{
private:
    vector<int> id, rank;
    int cnt;
public:
    UnionFind(int cnt) : cnt(cnt)
    {
        id = vector<int>(cnt);
        rank = vector<int>(cnt, 0);
        for (int i = 0; i < cnt; ++i)
            id[i] = i;
    }
    int find(int p)
    {
        if (id[p] == p)
            return p;
        return id[p] = find(id[p]);
    }
    int getCount()
    {return cnt;}
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    void connect(int p, int q)
    {
        int i = find(p), j = find(q);
        if (i == j)
            return;
        if (rank[i] < rank[j])
        {
            id[i] = j;
        }
        else
        {
            id[j] = i;
            if (rank[i] == rank[j])
                rank[j]++;
        }
        --cnt;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
     
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i+1; j < points.size(); j++)
            {
                
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];
                int val = abs(xi - xj) + abs(yi - yj);
                pq.push({val, {i, j}});
            }
        }
        UnionFind *uf = new UnionFind(points.size());
        int ans = 0;
        while(pq.size())
        {
            
            auto values = pq.top();
            pq.pop();
            int u = values.second.first;
            int v = values.second.second;
            if(!uf->connected(u,v))
            {
                uf->connect(u,v);
                ans += values.first;
            }
            
        }
        
        return ans;
        
    }
};