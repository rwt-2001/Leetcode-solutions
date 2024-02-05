class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]])
            {
                mp[s[i]] = 1e6;
            }else{
                mp[s[i]] = i+1;
            }
        }
        int ans = 1e6;
        
        for(auto val: mp)
        {
            ans=min(ans,val.second);
        }
        return ans==1e6?-1:ans-1;
    }
};