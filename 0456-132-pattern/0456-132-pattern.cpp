class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<pair<int,int>> stk;
        
        int leftMin = nums[0];
        for(int i = 1; i < nums.size() ; i++)
        {
            while(stk.size() && nums[i] > stk.top().first) stk.pop();
            
            
            
            if(stk.size() && stk.top().first > nums[i] && stk.top().second < nums[i]) return true;
            
            stk.push({nums[i], leftMin});
            leftMin = min(leftMin, nums[i]);
            
        }
        
        
        return false;
    }
};

