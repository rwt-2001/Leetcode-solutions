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
    

    int removeStones(vector<vector<int>>& stones) {
        int rowmax = 0;
        int colmax = 0;
        
        for(auto &val : stones){
            rowmax = max(val[0], rowmax);
            colmax = max(val[1], colmax);
        }
        int size = rowmax + colmax + 2;
        UnionFind uf(size);
        cout<<size<<" "<<endl;
        unordered_map<int,int> uniqueParents;
        
        for(auto &val: stones){
            int row = val[0];
            int col = val[1];
            cout<<row<<" "<<rowmax + 1 + col<<endl;
            uf.connect(row,rowmax + 1 + col);
            uniqueParents[row] = 1;
            // uniqueParents[col] = 1;
        }
        
        int uniqueCnt = 0;
        for(auto &mp : uniqueParents){
            if(uf.find(mp.first) == mp.first) uniqueCnt++;
        }
        return stones.size() - uniqueCnt;
    }
};