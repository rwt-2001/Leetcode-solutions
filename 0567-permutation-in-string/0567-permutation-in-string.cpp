class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size() ) return false;
        
        
        vector<int> targetMap(26), curMap(26);
        
        for(auto &c : s1){
            targetMap[c-'a']++;
        }
        
        int i = 0;
        int j = 0;
        
        while(j<s2.size()){
            
            if(j - i + 1 <= s1.size()){
                curMap[s2[j] - 'a']++;
            }else{
                
                if(targetMap == curMap) return true;
                curMap[s2[i++] - 'a']--;
                curMap[s2[j] - 'a']++;
            }
            j++;
            
        }
        
        return curMap == targetMap;
    }
};