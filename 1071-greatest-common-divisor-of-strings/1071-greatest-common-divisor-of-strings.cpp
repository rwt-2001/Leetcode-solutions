class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.size();
        int s2 = str2.size();
        
        if(s1 > s2)
        {
        
            if(s1%s2 == 0 && (str1.substr(0, s2) == str2) && (str1.substr(s1 - s2, s2) == str2)){
                return str2;
            }
            int i = 1;
            int ans = 0;
            while(i <= s1/2)
            {
                if(s2 % i == 0 && s1 % i == 0)
                {
                    ans = i;
                }
                i++;
            }
            
            int t = 0;
            while(t < s1)
            {
                if(str1.substr(t, ans) != str2.substr(0, ans))
                {
                    return "";
                }
                t += ans;
            }
            
            t = 0;
            while(t < s2)
            {
                if(str2.substr(t, ans) != str1.substr(0, ans))
                {
                    return "";
                }
                t += ans;
            }
            return str1.substr(0, ans);
            
            
        }
        else if(s1 < s2){
            
            if(s2%s1 == 0 && (str2.substr(0, s1) == str1) && (str2.substr(s2 - s1, s1) == str1)){
                return str1;
            }
            int i = 1;
            int ans = 0;
            while(i <= s1/2)
            {
                if(s2 % i == 0 && s1 % i == 0)
                {
                    ans = i;
                }
                i++;
            }
            int t = 0;
            while(t < s1)
            {
                if(str1.substr(t, ans) != str2.substr(0, ans))
                {
                    return "";
                }
                t += ans;
            }
            t = 0;
            while(t < s2)
            {
                if(str2.substr(t, ans) != str1.substr(0, ans))
                {
                    return "";
                }
                t += ans;
            }
            return str1.substr(0, ans);
            
        }
        else{
            if(str1 == str2) return str1;
            return "";
        }
        
        return "";
    }
};