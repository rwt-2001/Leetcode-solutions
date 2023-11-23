class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++)
        {
            
            int li = l[i];
            int ri = r[i];
            
            priority_queue<int> pq;
            
            for(int j = li; j <= ri; j++)
            {
                pq.push(nums[j]);
            }
            
            if(pq.size()==1 || pq.size() == 2)
            {
                ans.push_back(true);
                continue;
            }
            
            int prevEl = pq.top();
            pq.pop();
            int diff = prevEl - pq.top();
            int isAr = true;
            while(pq.size())
            {
                if(prevEl - pq.top() != diff)
                {
                    isAr = false;
                    break;
                }
                prevEl = pq.top();
                pq.pop();
            }
            
            ans.push_back(isAr);
            
        }
        
        return ans;
    }
};