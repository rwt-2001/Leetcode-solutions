//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool canMake(vector<int> &s, int k, int th)
    {
        k++;
        int pp = k;   
        int f = 0;
        int sum = 0;
        for(auto &ss: s)
        {
            sum+=ss;
            if(sum >= th)
            {
                sum = 0;
                k--;
            }
        }
        return  k<=0;
    }
    int maxSweetness(vector<int>& s, int N, int K) {
    // Write your code here.
    long long r = 0;
    for(auto &ss: s)
    {
        r += ss;
    }
    long long l = 0;
    int ans;
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        
        
        if(canMake(s, K, mid))
        {
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
        
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends