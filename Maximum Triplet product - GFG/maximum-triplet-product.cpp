//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long max1 = INT_MIN;
        long long max2 = INT_MIN;
        long long max3 = INT_MIN;
        
        long long min1 = INT_MAX;
        long long min2 = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            //handles max
            long long num = arr[i];
            if(num > max1){
                
                max3 = max2;
                max2 = max1;
                max1 = num;
                
            }else if(num > max2)
            {
                max3 = max2;
                max2 = num;
            }else if(num > max3){
                max3 = num;
            }
            
            //handles min
            if(num < min1)
            {
                min2 = min1;
                min1 = num;
                
            }else if(num < min2)
            {
                min2 = num;
            }
            
            
        }
        
        return max(min1*min2*max1,max1 * max2 * max3);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends