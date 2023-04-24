class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto s: stones)
        {
            pq.push(s);
        }
        
        while(pq.size()>1)
        {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            
            if(abs(s1 - s2) > 0) pq.push(abs(s1-s2));
        }
        
        
        return pq.size() == 1 ? pq.top() : 0;
    }
};