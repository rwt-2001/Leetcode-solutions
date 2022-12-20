class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n);
        stack<int> stk;
        
        int index = 0;
        while(index < n){
            while(!stk.empty() && t[stk.top()]  < t[index]){
                ans[stk.top()] = index - stk.top();
                stk.pop();
            }
            stk.push(index);
            index++;
        }
          return ans;
    }
};