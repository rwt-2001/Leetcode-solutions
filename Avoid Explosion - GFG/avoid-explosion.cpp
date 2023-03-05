//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
        
        UnionFind uf(n+1);
        
        vector<string> ans;
        
        for(auto &val : mix)
        {
            int a = val[0]-1;
            int b = val[1]-1;
            
            a = uf.find(a);
            b = uf.find(b);
            
            bool canMix = true;
            
            for(auto &dVal : danger)
            {
                int x = dVal[0]-1;
                int y = dVal[1]-1;
                x = uf.find(x);
                y = uf.find(y);
                if((x==a && y==b) || (x==b && y==a) )
                {
                    canMix = false;
                    break;
                }
            }
            
            if(canMix)
            {
                ans.push_back("Yes");
                uf.connect(a,b);
            }else{
                ans.push_back("No");
            }
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends