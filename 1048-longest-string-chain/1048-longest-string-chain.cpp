class Solution {
public:

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto a, auto b){
            return a.size() < b.size();
        });
        
        int ans = INT_MIN;
        int n = words.size();
        unordered_map<string,int> mp;
        
        for(auto &word : words){
            for(int i = 0;i<word.size();i++){
                string str = word.substr(0,i) + word.substr(i+1);
                mp[word] = max(mp[word],1 + mp[str]);
                ans = max(ans, mp[str]);
            }
            
            
        }
        return ans+1;
    }
};