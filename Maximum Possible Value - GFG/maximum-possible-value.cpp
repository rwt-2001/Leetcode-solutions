//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        long long sum = 0;
        int  minEl = INT_MAX;
        long long  pairs = 0;
        
        for(int i = 0; i < N; i++)
        {
            long long  pair = B[i]/2;
            if(pair)
            {
                sum += 2*pair*A[i];
                minEl = min(A[i], minEl);
                pairs += pair;
            }
        }
        
        if(pairs/2 == 0) return 0;
        
        return pairs%2==0 ? sum : sum-2*minEl;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends