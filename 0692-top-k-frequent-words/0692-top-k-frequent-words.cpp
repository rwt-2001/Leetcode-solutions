class Solution {
public:
    struct cmp{
        bool operator()(pair<int,string> &a, pair<int,string> &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        
        for(auto &str: words){
            mp[str]++;
        }
        
        priority_queue<pair<int,string> , vector<pair<int,string>>,  cmp> pq;
        
        vector<string> ans;
        for(auto &m : mp){
            pq.push({m.second, m.first});
            if(pq.size()> k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};