class Solution {
public:
    string reverseWords(string s) {
        
        stringstream strr(s);
        string curWord;
        string ans = "";
        while(strr>>curWord)
        {
           
            int end = curWord.size() -1;
            while(end >= 0)
            {
                ans += curWord[end--]; 
            }
            ans += " ";
            
            
        }
        ans.pop_back();
        return ans;
        
    }
};