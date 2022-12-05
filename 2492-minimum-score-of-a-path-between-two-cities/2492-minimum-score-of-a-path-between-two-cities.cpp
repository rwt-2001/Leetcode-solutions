class UnionFind{
    int  *id;
    int *rank;
    
    public:
    
    UnionFind(int size){
        size++;
        
        id = new int[size];
        rank = new int[size];
        for(int i = 0;i<size;i++) rank[i] = INT_MAX;
        iota(id, id+size, 0);
    }
    
    int findParent(int u){
        if(id[u]==u) return u;
        return findParent(id[u]);
    }
    
    void connectNode(int u, int v, int cost){
        u = findParent(u);
        v = findParent(v);
        if(v==1){
            id[u] = v;
            rank[u] = min(rank[u], cost);
            rank[v] = min({rank[v] ,cost, rank[u]});
        }
        else if(u==1){
            id[v] = u;
            rank[u] = min({rank[u], cost, rank[v]});
            rank[v] = min(rank[v] ,cost);
        }
      
        else{
            id[u] = v;
            rank[u] = min({rank[u], cost, rank[v]});
            rank[v] = min({rank[v] ,cost, rank[u]});
        }
        
       
        

    }
    
    int returnMin(){
        return rank[1];
    }
    
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind uf(n);
        
        for(auto &road : roads){
            uf.connectNode(road[0], road[1], road[2]);
        }
        return uf.returnMin();
    }
};