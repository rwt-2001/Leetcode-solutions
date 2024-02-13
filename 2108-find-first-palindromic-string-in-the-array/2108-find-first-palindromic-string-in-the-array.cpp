class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        string ans = "";
        
        for(auto &word: words)
        {
            
            bool  flag = true;
            
            int l = 0;
            int r = word.size() - 1;
            
            while(l < r)
            {
                if(word[l]!=word[r]){
                    flag = false;
                    break;
                }
                l++;
                r--;
            }
            
            if(flag)
            {
                ans = word;
                break;
            }
            
        }
        
        return ans;
    }
};