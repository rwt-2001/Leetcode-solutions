//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int i = 0;
        for(int len = 1; len < str.size() ; len++)
        {
            if((len != 1 && str[len - 1] == str[len]) || (str[len] < str[len - 1]))
            {
                i = len;
            }
            else {break;}
            
        }
        
        string ans = str.substr(0,i+1);
        
        string rev = ans;
        reverse(rev.begin(), rev.end());
        
        return ans+rev;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends