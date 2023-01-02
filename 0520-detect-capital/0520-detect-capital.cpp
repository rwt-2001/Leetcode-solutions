class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool cap = 0;
        bool small = 0;
        
         if(word[0] - 'a' >= 0 && word[0] - 'a' <= 25 )small = true;
        for(int i = 1;i<word.size();i++){
            
            if(word[i] - 'A' >= 0 && word[i] - 'A' <= 25 )
                cap = true;
            if(word[i] - 'a' >= 0 && word[i] - 'a' <= 25 )
                small = true;
            
            if(cap && small) return false;
            
        }
        
        return true;
    }
};