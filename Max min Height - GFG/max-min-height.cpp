//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    bool canMake(int value, vector<int> a, int window, int k)
    {   
     for(int i = 0; i < a.size();i++)
     {
         if(a[i] < value){
             int inc = value - a[i];
             if(inc > k) return false;
             k-=inc;
             
             for(int j = i ; j < a.size() && j < i+window; j++)
             {
                a[j]+=inc;
             }
         }
     }
     
     return true;
    }
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
            long long start = 1;
            long long end = *min_element(a.begin(), a.end()) + k;
            long long ans = -1;
            
            while(start <= end)
            {
                long long mid = start + (end - start) / 2;
                
                if(canMake(mid, a, w, k)){
                    ans = mid;
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends