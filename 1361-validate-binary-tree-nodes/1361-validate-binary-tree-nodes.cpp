
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
        
        id[j] = i;

        --cnt;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        UnionFind *uf = new UnionFind(n);
        
        for(int i = 0; i < n; i++)
        {
           if(l[i] != -1)
           {
               if(uf->find(l[i]) != l[i] || uf->connected(l[i],i)) return false;
               uf->connect(i, l[i]);
           }
            if(r[i] != -1)
           {
               if(uf->find(r[i]) != r[i] || uf->connected(r[i],i)) return false;
               uf->connect(i, r[i]);
           }
        }
        
        return uf->getCount() == 1;
    }
};