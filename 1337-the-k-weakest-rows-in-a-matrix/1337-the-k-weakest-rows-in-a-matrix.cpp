class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if (a.first < b.first) {
            return true;
        }
        else if (a.first == b.first
                 && a.second < b.second) {
            return true;
        }
 
        return false;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        
        
        for(int i = 0; i < mat.size();i++)
        {
            int cnt = 0;
            for(int j = 0; j < mat[i].size();j++)
            {
                cnt += mat[i][j];
            }
            pq.push({cnt,i});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans(k);
        
        while(k > 0)
        {
            ans[k-1] = pq.top().second;
            k--;
            pq.pop();
        }
        return ans;
    }
};