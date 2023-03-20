//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        queue<pair<int,int>> q;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(grid[i][j]=='X')
                {
                    q.push({i,j});
                }
            }
        }
        
        int ans = 0;
        
        while(q.size())
        {
            
            
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                        
                pair<int,int> rc = q.front();
                q.pop();
                if(grid[rc.first][rc.second]=='Y') return ans;
                int dir[] = {0,1,0,-1,0};
                
                for(int j= 0;j < 4; j++)
                {
                    int newR = dir[j] + rc.first;
                    int newC = dir[j+1] + rc.second;
                    if(newR<0 || newR >= N || newC < 0|| newC >= M|| grid[newR][newC] == '#' || grid[newR][newC] == 'X'){
                        continue;
                    }
                    
                    q.push({newR, newC});
                    if(grid[newR][newC] != 'Y')
                    grid[newR][newC] = '#';
                    
                }
                
                
            }
            ans++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends