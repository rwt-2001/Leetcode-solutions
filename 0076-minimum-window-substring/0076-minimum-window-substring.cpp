class Solution {
public:
    bool isEqual(vector<int> &t, vector<int> &f){
        for(int i = 0;i<256;i++){
            if(f[i] < t[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string target) {
        vector<int> t(256);
        vector<int> f(265);
        
        for(auto &c : target){
            t[c]++;
        }
        
        
        int i = 0;
        int start= 0, end=INT_MAX;
        
        for(int j = 0;j<s.size();j++){
            
            if(t[s[j]]) f[s[j]]++;
            
            while(isEqual(t, f)){
                
                if(end - start > j - i){
                    start = i;
                    end = j;
                }
                
                if(t[s[i]]) f[s[i]]--;
                i++;
            }
            
            
        }
        
        return end==INT_MAX ? "" : s.substr(start, end-start+1);
        
    }
};