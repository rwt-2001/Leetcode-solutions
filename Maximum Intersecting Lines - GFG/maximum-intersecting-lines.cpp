//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        vector<pair<int, bool>> points;
        for(auto l: lines)
        {
            points.push_back({l[0], false});
            points.push_back({l[1], true});
        }
        
        sort(points.begin(), points.end());
        
        int cur = 0;
        int ans = 0;
        for(int i = 0; i < points.size(); i++)
        {
            if(!points[i].second)
            {
                ans++;
            }else{
                ans--;
            }
            
            cur = max(ans, cur);
        }
        
        return cur;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends