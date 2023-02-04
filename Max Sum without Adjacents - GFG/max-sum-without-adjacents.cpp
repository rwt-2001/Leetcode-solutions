//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *nums, int n) {
	
        if(n==1) return nums[0];
        int sz = n;
        
        vector<int> dp (sz+3,0);
        for(int i = sz-1;i>=0;i--){
            dp[i] = nums[i] + max(dp[i+2], dp[i+3]);
        }
        
        return max(dp[0], dp[1]);
    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends