class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        
        int ans = 0;
        for(auto p : prices)
        {
            minVal = min(minVal,p);
            
            ans = max(ans, p - minVal);
        }
        
        return ans;
    }
};