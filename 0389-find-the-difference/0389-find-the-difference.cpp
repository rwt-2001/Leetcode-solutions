class Solution {
public:
    char findTheDifference(string s, string t) {
        int num = 0;
        for(int i = 0; i < t.size(); i++)
        {
            num = (num ^ (1 << (t[i] - 'a')));
            if(i < s.size())
            {
                num = (num ^ (1 << (s[i] - 'a')));
            }
        }
        char ans;
     
        for(int i = 0; i < 26;i++)
        {
            if(num & (1<<i)){
                ans = 'a' + i;
                break;
            }
        }
        return ans;
    }
};