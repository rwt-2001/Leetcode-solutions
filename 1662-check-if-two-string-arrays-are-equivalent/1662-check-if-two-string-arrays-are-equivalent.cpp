class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0;
        int j = 0;
        int ci = 0;
        int cj = 0;
        
        while(i < word1.size() && j < word2.size()){
            if(ci == word1[i].size()){
                i++;
                ci = 0;
            }
            if(cj == word2[j].size()){
                j++;
                cj = 0;
            }
            if(i == word1.size() || j == word2.size()) break;
            if(word1[i][ci] != word2[j][cj]) return false;                        
            ci++;
            cj++;
            
        }
        
        return i == word1.size() && j == word2.size();
        
    }
};