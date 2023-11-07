class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        
        vector<int> time;
        int n = dist.size();
        int saved = 0;
        int chargeT = 0;
        for(int i = 0; i < n;i++)
        {
            time.push_back(ceil((double)dist[i] / speed[i]));
        }
        
        sort(time.begin(), time.end());
        
        for(int i = 0; i < n; i++)
        {
            if(chargeT >= time[i]) break;
            saved++;
            chargeT++;
        }
        return saved;
        
    }
};

 
