class Solution {
    int mod = 1e9 + 7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> prefix;
        
        for(int i = 0;i<=31;i++){
            int mask = 1 << i;
            if(mask & n){
                prefix.push_back(1<<i);
            }
        }
        vector<int> ans;
        
        for(auto & q : queries){
            int i = q[0];
            int j = q[1];
            
            long long x = 1;
            
            while(i<=j){
                x = (x*prefix[i]) % mod;
                i++;
            }
            ans.push_back((int)x);
        }
        
        return ans;
    }
};