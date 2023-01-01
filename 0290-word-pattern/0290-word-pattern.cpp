class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;
        map<string, int> wp;
        stringstream ss(s);
        string word;
        
        int pn = pattern.size();
        int sn = s.size();
        
        int i = 0;
        while(ss >> word){
            // cout<<pattern[i]<<" "<<word<<endl;
            if(i == pn) return false;
            
            if(mp.count(pattern[i]) == 0){
                if(wp[word]) return false;
                mp[pattern[i]] = word;
                wp[word] = 1;
                
            }
                
            
            else if(mp[pattern[i]] != word) return false;
            i++;
        }
        
        
        return i == pn ? true : false;
    }
};