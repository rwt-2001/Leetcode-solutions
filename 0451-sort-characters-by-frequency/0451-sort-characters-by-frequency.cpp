class Solution {
public:
    string frequencySort(string s) {
        map<int,int> mp;
        
        for(auto &c : s){
            mp[c]++;
        }
        
        
        pair<int,int> arr[s.size()];
        int i=0;
        for(auto &m : mp){
            arr[i++] = {m.second, m.first};
        }
        sort(arr, arr+s.size(), greater<pair<int,int>>());
        string ans ="";
        
        for(auto &val : arr){
            int n = val.first;
            char c = val.second;
            while(n--) ans+=c;
            
        }
        
        return ans;
    }
};