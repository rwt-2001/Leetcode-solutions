class Solution {
public:
    string frequencySort(string s) {
        map<int,int> mp;
        
        for(auto c: s)
        {
            mp[c]++;
        }
        
        vector<pair<int,char>> arr;
        
        for(auto &val: mp)
        {
            arr.push_back({val.second, val.first});
        }
        
        sort(arr.begin(), arr.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        
        string ans = "";
        for(auto val: arr)
        {
            for(int i = 0; i < val.first; i++)
                ans+=val.second;
        }
        
        return ans;
    }
};