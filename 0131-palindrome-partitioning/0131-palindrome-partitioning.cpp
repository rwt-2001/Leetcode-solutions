class Solution {
    vector<vector<string>> answer;
public:
    bool isPalindrome(string str)
    {
        if(str == "") return false;
        int i = 0;
        int j = str.size() - 1;
        while(i < j)
        {
            if(str[i++] != str[j--]) return false;
        }  
        return true;
    }
    void solve(string &s, int i, int j, vector<string> &ans)
    {
        if(i >= s.size())
        {
            if(ans.size() == 0) return;
            for(auto &str : ans)
            {
                if(!isPalindrome(str)) return;
            }
            answer.push_back(ans);
        }
        if(j >= s.size()) return;
        
        ans.push_back(s.substr(i,j - i + 1));
        solve(s, j + 1, j + 1, ans);
        
        ans.pop_back();
        solve(s,i, j + 1, ans);
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        solve(s, 0, 0, ans);
        return answer;
    }
};