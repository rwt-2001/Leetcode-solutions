class Solution {
public:
    vector<string> res;
    map<char,string> mp;
    void solve(int i, string &digit, string letter)
    {
        if(letter.size() == digit.size())
        {
            res.push_back(letter);
            return;
        }
        
        string chars = mp[digit[i]];
        for(int j = 0; j < chars.size(); j++)
        {
            solve(i + 1, digit, letter + chars[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(0, digits,"");
        return res;
    }
};