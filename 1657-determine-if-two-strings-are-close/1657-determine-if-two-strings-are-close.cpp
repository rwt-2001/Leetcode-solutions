class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word2.size() != word1.size()) return false;
        int n = word1.size();
        vector<int> map1(26);
        vector<int> map2(26);
        
        for(int i = 0;i<n;i++){
            map1[word1[i] - 'a']++;
        }
        
        for(auto &word : word2){
            if(map1[word - 'a'] ==0 ) return false;
            map2[word - 'a']++;
        }
         map<int,int> w1fr;
        map<int,int> w2fr;
        
        for(auto m : map1){
            w1fr[m]++;
        }
        for(auto m : map2){
            w2fr[m]++;
        }
        
        map<int,int> :: iterator itr1 =w1fr.begin();
        map<int,int> :: iterator itr2 =w2fr.begin();
        
        while(itr1 != w1fr.end() && itr2!=w2fr.end()){
            if(itr1->first != itr2->first || itr1->second != itr2->second) return false;
            itr1++;
            itr2++;
        }
        return itr1 == w1fr.end() && itr2==w2fr.end();
    }
};