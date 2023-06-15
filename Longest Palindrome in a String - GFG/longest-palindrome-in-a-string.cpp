//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int sz = 0;
        string ans = "";
        while(sz < S.size())
        {
            int i = sz;
            int j = sz + 1;
            int len = 0;
            while(i >= 0 && j< S.size() && S[i] == S[j])
            {
                    len += 2;
                    i--;
                    j++;
            }
            
            if(len > ans.size())
            {
                ans = S.substr(i+1, len);
            }
            
            i = sz - 1;
            j = sz + 1;
            len = 1;
            while(i >= 0 && j< S.size() && S[i] == S[j])
            {
                    len += 2;
                    i--;
                    j++;
            }
            if(len > ans.size())
            {
                ans = S.substr(i+1, len);
            }
            
            
            sz++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends