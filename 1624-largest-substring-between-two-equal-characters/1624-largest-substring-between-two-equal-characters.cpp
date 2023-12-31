class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int> lastOcc(26, -1);
        
        for(int i = 0; i < s.size(); i++)
        {
            if(lastOcc[s[i]-'a'] == -1)
            {
                lastOcc[s[i]-'a'] = i;
            }else{
                ans = max(ans, i - lastOcc[s[i]-'a'] - 1);
            }
        }
        
        return ans;
    }
};