//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(int N) {
        long long n = N;
        long long mid;
        if(n&1)
        {
            mid = n/2;
            long long element = 2*mid;
            return (mid*(element + 2))/2;
        }
        // 1 3 5 7
        
        mid = n/2;
        
        long long element = 2*(mid) - 1;
        
        return (mid*(1 + element ))/2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends