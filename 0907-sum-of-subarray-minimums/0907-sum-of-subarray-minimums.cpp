class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> minR(arr.size(), arr.size());
        vector<int> minL(arr.size(), -1);
        
        
        stack<pair<int,int>> stk;
        for(int i = 0; i < arr.size(); i++)
        {
            while(stk.size() && stk.top().first > arr[i])
            {
                pair<int,int> topEl = stk.top();
                minR[topEl.second] = i;
                stk.pop();
            }
            stk.push({arr[i], i});
        }
        
        while(stk.size()) stk.pop();
        
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            while(stk.size() && stk.top().first >= arr[i])
            {
                pair<int,int> topEl = stk.top();
                minL[topEl.second] = i;
                stk.pop();
            }
            stk.push({arr[i], i});
        }
        
        
        int mod = 1e9 + 7;
        long long ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            int l = minL[i];
            int r = minR[i];
            
            // cout<< (1l*(i-l)*(r-i))<<endl;
            ans = (ans +  (1l*(i-l)*(r-i))*arr[i]) % mod;
        }
        
        return ans;
    }
};