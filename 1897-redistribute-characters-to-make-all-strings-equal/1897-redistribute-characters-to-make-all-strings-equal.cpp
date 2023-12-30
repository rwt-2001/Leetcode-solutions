class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int n = words.size();
        
       vector<int> mp(26,0);
        for(auto word : words)
        {
            for(auto chars: word)
            {
                mp[chars-'a']++;
            }
        }
        
        
        for(auto val: mp)
        {
            if(val%n)
            {
                return false;
            }
        }
        
        return true;
    }
};