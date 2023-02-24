class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int mv = 0;
        int res = INT_MAX;
            
        for(auto n : nums)
        {
            int temp = n;
            while(n%2==0) n/=2;
            
            pq.push({n, max(temp, 2*n)});
            mv = max(n, mv);
        }
        
        while(pq.size() == nums.size())
        {
            int minV = pq.top().first;
            int maxV = pq.top().second;
            res = min(res, mv - minV);
            pq.pop();
            
            if(maxV > minV)
            {
                
                pq.push({minV*2, maxV});
                mv = max(minV*2, mv);
            }
        }
        
        return res;
        
    }
};