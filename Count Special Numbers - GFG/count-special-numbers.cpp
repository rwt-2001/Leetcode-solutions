//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        unordered_map<int,int> mp;
        for(auto num : arr)
        {
            mp[num]++;
        }
        
        
        int ans = 0;
        for(int i = 0; i  < N; i++)
        {
            int cur_num = arr[i];
            int flag = 0;
            mp[cur_num]--;
            for(int j = 1; j*j <= cur_num; j++)
            {
                if((mp[j] && (cur_num%j)==0) || (mp[cur_num/j] && (cur_num%(cur_num/j))==0)){
                    
                    flag = 1;
                    ans++;
                    break;
                }
            }
            
            mp[cur_num]++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends