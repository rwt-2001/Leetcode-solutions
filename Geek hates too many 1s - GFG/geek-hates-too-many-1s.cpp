//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int num = 0;
        for(int i = 31; i>=0; i--)
        {
            if(n & (1<<i)){
                num++;
                if(num==3){
                    n = n & (~(1<<i));
                    num = 0;
                }
            }
            else{
                num=0;
            }
        }
        
        return n;
    }
};
//

//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends