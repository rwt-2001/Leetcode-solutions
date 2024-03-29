class Compare{
  public:
    bool operator()(pair<int,int> below, pair<int,int> above)
    {
         return above.second > below.second;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        int n = profits.size();
        for(int i = 0; i < n ; i++)
        {
            arr.push_back({capital[i], profits[i]});
        }
        
        
        sort(arr.begin(), arr.end());
            
        
        priority_queue<int> pq;
        int i = 0;
        while(k>0)
        {
            while(i < n && w >= arr[i].first)
            {
                pq.push({arr[i++].second});
            }
            if(pq.size())
            {
                 w += pq.top();
                 pq.pop();
            }
            k--;
            
        }
        

        
        return w;
        
    }
};