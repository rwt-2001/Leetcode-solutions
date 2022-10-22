class Solution {
public:
    
    bool areEqual(vector<int> &sm, vector<int> &tm){
        
        for(int i = 0;i<256;i++){
            if(tm[i] && tm[i] > sm[i]) return false;
        }    
        return true;
    }
    
    string minWindow(string s, string t) {
        vector<int> sm(256), tm(256);
        for(auto &c : t){
            tm[c]++;
        }
        
        int i = 0,j = 0;
        int start = 0, end = INT_MAX;
        
        while(j<s.size()){
            
            sm[s[j]]++;
            
            while(areEqual(sm, tm) && i<=j){
                
                if((end - start) > (j - i)){
                    start = i;
                    end = j;
                }
                
                sm[s[i]]--;
                i++;
            }
            j++;
            
        }

        
        
        return end != INT_MAX ? s.substr(start, end - start+1) : "";
        
    }
};