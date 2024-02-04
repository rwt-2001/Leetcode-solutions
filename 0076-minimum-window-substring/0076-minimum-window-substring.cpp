class Solution {
public:
    bool haveSame(map<char,int> &tmp, map<char,int>&smp)
    {
        for(auto val : tmp)
        {
            
            if(val.second > smp[val.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        
       map<char,int> tmp;
       map<char,int> smp;
        int I = -1,  J=-1;
        for(auto &cc: t)
        {
            tmp[cc]++;
        }
        string ans = "";
        int len = INT_MAX;
        int j = 0;
        for(int i = 0; i < s.size(); i++)
        {
            smp[s[i]]++;
            
            while(haveSame(tmp, smp))
            {
                
                if(i - j + 1 < len)
                {
                    len = i - j + 1;
                    I = i;
                    J=j;
                }
                smp[s[j++]]--;
                
            }
            
        }
        if(I == -1) return "";
        return s.substr(J, I - J + 1);
    }
};