class Solution {
public:
    
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int, vector<int>, greater<int>> minH;
        int sum = 0;
        
        for(int i = 1; i < h.size(); i++)
        {
            if(h[i] - h[i - 1] > 0)
            {
                minH.push(h[i] - h[i-1]);
            }
            
            if(minH.size() > l){
                int curT = minH.top();
                minH.pop();
                
                if(sum + curT > b) return i-1;
                sum += curT;
            }
            
        }
        
        
        return h.size() - 1;
    }
};

    