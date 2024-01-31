class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> stk;
        
        vector<int> ans(t.size(), 0);
        for(int i = 0;i < t.size(); i++)
        {
            while(stk.size() && t[stk.top()] < t[i])
            {
                int top_Ind = stk.top();
                stk.pop();
                
                ans[top_Ind] = i - top_Ind;
            }
            stk.push(i);
        }
        
        return ans;
        
    }
};