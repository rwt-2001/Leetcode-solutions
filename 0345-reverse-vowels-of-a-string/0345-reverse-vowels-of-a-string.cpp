class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        map<char,int> mp{
            {'a',1},{'e',1},{'i',1},{'o',1},{'u',1},{'A',1}, {'E',1}, {'I',1}, {'O',1}, {'U',1}
        };
        while(i<j){
            
            if(mp[s[i]] && mp[s[j]]){
                swap(s[i], s[j]);
                i++;
                j--;
            }else if(mp[s[i]]){
                j--;
            }else if(mp[s[j]]){
                i++;
            }else{
                i++;j--;
            }
        }
        
        return s;
    }
};