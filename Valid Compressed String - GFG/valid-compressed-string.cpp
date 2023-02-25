//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        
        int j = 0;
        int i = 0;
        while(i < S.size())
        {
            int num = 0;
            while(j<T.size() && T[j] >= '0' && T[j] <='9')
            {
                num*=10;
                num += T[j++] - '0';
            }
            i += num;
            if(i==S.size() && j==T.size())
                return 1;
            if(i > S.size()) return 0;
            if(T[j] != S[i])
                return 0;
            i++;
            j++;
        }
        
        return i==S.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends