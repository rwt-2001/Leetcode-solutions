//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        //Code Here
        int n1 = s1.size(), n2 = s2.size();
        int ans = INT_MAX;
        for(int i = 0; i <= s1.size() - s2.size(); i++)
        {
            string str = s1;
            int res = 0;
            for(int j = 0; j < s2.size(); j++)
            {
                if(str[i+j] != s2[j])
                {
                    str[i+j] = s2[j];
                    res++;
                }
            }
            int start = 0, end = s1.size() - 1;
            bool flag = 1;
            while(start < end)
            {
                if(str[start] != str[end]){
                    if(start>= i && start < i+s2.size()&& end>= i  && end < i+s2.size()){
                        flag = 0;
                        break;
                    }
                    res++;
                }
                start++;
                end--;
            }
            if(flag){
                ans = min(ans, res);
            }
            
            
        }
        
        return INT_MAX==ans ? -1 : ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends