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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UF *bobUf = new UF(n+1);
        UF *aliceUf = new UF(n+1);
        int extras = 0;
        sort(edges.rbegin(), edges.rend());
        for(auto e : edges)
        {
            int u = e[1];
            int v = e[2];
            if(e[0]==1)
            {
                if(aliceUf->find(u) == aliceUf->find(v))
                {
                    extras++;
                }else{
                    aliceUf->connect(u, v);
                }
            }
            else if(e[0]==2)
            {
                if(bobUf->find(u) == bobUf->find(v))
                {
                    extras++;
                }else{
                    bobUf->connect(u, v);
                }
            }
            else if(e[0]==3)
            {
                if(bobUf->find(u) == bobUf->find(v) && aliceUf->find(u) == aliceUf->find(v))
                {
                    extras++;
                }else{
                    bobUf->connect(u, v);
                    aliceUf->connect(u, v);
                }
            }
        }
        if(bobUf->getCount() > 2|| aliceUf->getCount() > 2) return -1;
       
        return extras;
    }
};