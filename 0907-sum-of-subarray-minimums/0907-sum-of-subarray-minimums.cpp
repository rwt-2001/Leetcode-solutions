class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        stack<int> stk;
        vector<int> prev(n,-1);
        vector<int> next(n,n);
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && arr[stk.top()] >= arr[i] ){
                next[stk.top()] = i;
                stk.pop();
                
            }
            stk.push(i);
            
        }
        
        for(int i = n-1;i>=0;i--){
            
            while(!stk.empty() && arr[stk.top()] > arr[i] ){
                prev[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        
        
        int ans = 0;
        
        for(int i = 0;i<n;i++){
              int subarrs =  ( (long long) (next[i] - i) * (long long)(i - prev[i]) ) % mod;
                
              ans =  ((long long)((ans % mod + (((long long)arr[i] * (long long)subarrs)) % mod)))%mod;
        }
        
        return ans;
        
    }
};