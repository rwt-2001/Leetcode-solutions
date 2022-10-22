class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {

        if(s1.size() > s2.size() ) return {};
        
        
        vector<int> targetMap(26), curMap(26);
        
        for(auto &c : s1){
            targetMap[c-'a']++;
        }
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(j<s2.size()){
            
            if(j - i + 1 <= s1.size()){
                curMap[s2[j] - 'a']++;
            }else{
                
                if(targetMap == curMap){
                    ans.push_back(i);
                };
                curMap[s2[i++] - 'a']--;
                curMap[s2[j] - 'a']++;
            }
            j++;
            
        }
        if(targetMap == curMap){
                    ans.push_back(i);
        };
        return ans;

    }
};