class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        int index = 0;
        for( ;len < k;index++)
        {
            char c = s[index];
            if(c >= '0' && c<='9')
            {
                len = len* (c-'0');
            }else{
                len++;
            }
        }
        
        string ans = "";
        for(int i = index-1; i>=0;i--)
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

