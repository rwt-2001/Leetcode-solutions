class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        vector<int> tar(26);
        for(auto c : s1)
        {
            tar[c-'a']++;
        }
        
        vector<int> tar2(26);
        int i = 0, j = 0;
        
        while(j < s2.size())
        {
            if(j - i + 1 <= s1.size())
            {
                tar2[s2[j] - 'a']++;
                j++;
            }
            else{
                if(tar == tar2) return true;
                tar2[s2[i] - 'a']--;
                tar2[s2[j] - 'a']++;
                i++;
                j++;
            }
            
            
        }
        return tar == tar2;
    }
};