class Solution {
    vector<string> res;
public:
    bool isValid(string IP)
    {
        int n = IP.size();
        
        string str = "";
        for(int i = 0; i < n; i++)
        {
            if(IP[i] == '.')
            {
                int str_n = str.size();
                if(str_n > 1 && str[0] == '0') return false;
                
                int num = stoi(str);
                
                if(num < 0 || num > 255) return false;
                
                str = "";
                
            }else{
                str += IP[i];
            }
        }
        int str_n = str.size();
        if(str_n > 1 && str[0] == '0') return false;
                
        int num = stoi(str);
                
        if(num < 0 || num > 255) return false;
                
        
        return true;
    }
    void ValidIP(string &s, int dots, int index, string IP, int curLen){
        // cout<<index<<"-->"<<s.size()<<" "<<endl;
        
        
        if(index >= s.size())
        {
            if(isValid(IP) && dots == 3){
                // cout<<IP<<endl;
                res.push_back(IP);
            }
            return;
        }
        //Without dot
        IP.push_back(s[index]);
        if(curLen < 3)
        {
            ValidIP(s, dots, index + 1, IP, curLen + 1);
        }        
        
        //insert dot
        if(curLen && dots < 3)
        {
            IP.pop_back();
            IP.push_back('.');
            IP.push_back(s[index]);
            ValidIP(s, dots + 1, index + 1, IP, 1);
        }
            
    
        
    }
    vector<string> restoreIpAddresses(string s) {
        string ip = "";
        ValidIP(s, 0,0,ip, 0);
        return res;
    }
};