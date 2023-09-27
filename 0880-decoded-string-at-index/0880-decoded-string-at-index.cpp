class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        int index;
        for(int i = 0;len < k;i++)
        {
            char c = s[i];
            if(c >= '0' && c<='9')
            {
                len = len* (c-'0');
            }else{
                len++;
            }
            index = i;
        }
        
        string ans = "";
        for(int i = index; i>=0;i--)
        {
            char c = s[i];
            if(c >= '0' && c<='9' && len)
            {
                len = len / (c-'0');
                k = k%len;
            }
            else if(k%len--==0 || len==0)
            {
                return string(1,s[i]);
                    
            }
                
            
        }
        
        return ans;
    }
};

