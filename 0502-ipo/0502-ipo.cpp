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
            
        for(auto val : arr)
        {
            cout<<val.first<<" "<<val.second<<endl;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        int i = 0;
        while(k>0 && i < n)
        {
            while(i < n && w >= arr[i].first)
            {
                pq.push({arr[i++]});
            }
            if(pq.size())
            {
                 w += pq.top().second;
                 pq.pop();
            }
            k--;
            
        }
        
        while(k>0 && pq.size())
        {
            w += pq.top().second;
            pq.pop();
            k--;
        }
        
        return w;
        
    }
};