//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long int ans = 0;
    
    for(int index = 0; index < n; index++)
    {
        long long int count = 0;
        if(arr[index]==0)
        {
            while(index < n && arr[index]==0)
            {
                index++;
                count++;
            }
        }
        
        ans += count*(count + 1)/2;
    }
    
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends