class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mpn;
        for(auto &num : arr)
        {
            mpn[num]++;
        }
        
        map<int,int> mpo;
        
        for(auto &val: mpn)
        {
            if(mpo[val.second]) return false;
            mpo[val.second]++;
        }
        
        
        
        return true;
    }
};