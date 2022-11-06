class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pql;
        priority_queue<int, vector<int>, greater<int>> pqr;
        int n = costs.size();
        int i = 0;
        int j = n-1;
        
        long long ans = 0;
        
        while(k>0){
            while(i <= j && pql.size() < candidates){
                pql.push(costs[i]);
                i++; 
            }
            while(i <= j && pqr.size() < candidates){
                pqr.push(costs[j]);
                j--;
            }
            
            if(pqr.empty() || (!pql.empty() && pql.top() <= pqr.top()) ){
                ans += pql.top();
                pql.pop();
            }else{
                ans += pqr.top();
                pqr.pop();
            }
            k--;
        }

        return ans;
    }
};