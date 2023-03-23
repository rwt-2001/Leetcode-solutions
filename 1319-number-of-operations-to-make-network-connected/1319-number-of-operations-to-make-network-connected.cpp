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
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int cable = 0;
        for(auto entry : connections)
            
        {
            if(uf.find(entry[0])==uf.find(entry[1])) {
                cable++;
            }
           
            uf.connect(entry[0], entry[1]);
        }
       return (cable < (uf.getCount()-1) ) ? -1 : uf.getCount()-1;
    }
};