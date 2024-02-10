class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        
        for(int i = 0; i < s.size(); i++)
        {
            int l = i-1;
            int j = i+1;
            
            int cnt = 1;
            while(l >= 0 && j < s.size() && s[l]==s[j])
            {
                cnt++;
                l--;
                j++;
            }
            l = i;
            j = i+1;
            while(l >= 0 && j < s.size() && s[l]==s[j])
            {
                cnt++;
                l--;
                j++;
            }
            ans += cnt;
        }
        
        return ans;
    }
};