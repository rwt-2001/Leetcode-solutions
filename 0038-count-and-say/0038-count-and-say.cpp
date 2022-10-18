class Solution {
public:
    string count(int n){
        if(n==1){
            return "1";
        }
        
        string str = count(n-1);
        
        string res = "";
        
        int j = 0;
        int i = 0;
        while(j<str.size()){
            if(str[i] != str[j]){
                res+= to_string(j-i);
                res+=str[i];
                i=j;
            }    
            j++;
            
        }
        res+= to_string(j-i);
        res+=str[i];
        
        return res;
    }
    string countAndSay(int n) {
        return count(n);
    }
};