class UF
{
private:
    vector<int> id, rank;
    int cnt;
    public:
    UF(int cnt) : cnt(cnt)
    {
        id = vector<int>(cnt);
        rank = vector<int>(cnt, 0);
        for (int i = 0; i < cnt; ++i)id[i] = i;
    }
    int find(int p)
    {
        if (id[p] == p)
            return p;
        return id[p] = find(id[p]);
    }
    int getCount()
    {
        return cnt;
    }
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UF uf(n);
        vector<pair<vector<int>, int>> newQ;
        sort(edgeList.begin(), edgeList.end(), [&](auto &a, auto &b)
             {
                return a[2] < b[2]; 
             });
        
        for(int i = 0; i < queries.size(); i++)
        {
            newQ.push_back({queries[i],i});
        }
        
        sort(newQ.begin(), newQ.end(), [&](auto &a, auto &b)
             {
                return a.first[2] < b.first[2]; 
             });
        int index = 0;
        
        vector<bool> ans(queries.size());
        
        for(auto &q: newQ)
        {
            
            int limit = q.first[2];
            
            for(int i = index; i < edgeList.size(); i++)
            {
                if(edgeList[i][2] >= limit)
                {
                    index = i;
                    break;
                }
                uf.connect(edgeList[i][0], edgeList[i][1]);
                index = i;
            }
            
            ans[q.second] = (uf.find(q.first[0])==uf.find(q.first[1]));
            
        }
        
        
        return ans;
    }
};






















