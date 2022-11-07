class Solution {
public:
    int maximum69Number (int num) {
        string numstr = to_string(num);
        for(auto &n : numstr){
            if(n=='6'){
                n = '9';
                break;
            }
        }
        
        return stoi(numstr);
    }
};