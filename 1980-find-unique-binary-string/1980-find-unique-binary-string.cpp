class Solution {
    int n;
    map<string, int> mp;
public:
    
    pair<bool, string> solve(string ans)
    {
        if(ans.size() == n)
        {
            pair<bool, string> res;
            res.first = true;
            res.second = ans;
            if(mp[ans])
            {
                res.first = false;
            }
            return res;
        }
        
        pair<bool, string> anss;
         ans += '0';
        
        anss = solve(ans);
        if(anss.first)
        {
            return anss;
        }
        
        ans.pop_back();
        ans+='1';
        anss = solve(ans);
        
        return anss;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].size();
        for(auto str: nums)
        {
            mp[str]++;
        }
        return solve("").second;
    }
};