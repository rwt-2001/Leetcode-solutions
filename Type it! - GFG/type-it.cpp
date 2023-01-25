//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int maxLen = 0;
        int n = s.size();
        for(int i = 0; i < n ; i++)
        {
            int k = 0;
            int found = 1;
            for(int j = i + 1; j < n && k <= i; j++)
            {
                if(s[j] != s[k])
                {
                    found = 0;
                    break;
                }
                k++;
            }
            
            if(found && k==i+1)
            {
                maxLen = max(maxLen, i + 1);
            }
        }
        
        
        return maxLen > 0 ? n - maxLen + 1 : n;
    }
};
//aaaaaaabaaaaa

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends