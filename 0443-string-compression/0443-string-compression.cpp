class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int len = 0;
        int index = 0;
        
        while(j<chars.size()){
            if(chars[i]==chars[j]){
                len++;
                j++;
            }
            
            else
            {
                // cout<<chars[i]<<" "<<len<<endl;
                if(len > 1) {
                    chars[index++] = chars[i];
                    string number = to_string(len);
                    for(auto &c : number){
                        chars[index++] =c;
                    }
                }
                else {
                    chars[index++] = chars[i];
                }
                len = 0;
                i = j;
                
            }
            
        }
     
        if(len > 1) {
            chars[index++] = chars[i];
            string number = to_string(len);
            
            for(auto &c : number){
                chars[index++] =c;
            }
        }
        else {
            // cout<<chars[i];
            chars[index++] = chars[i];
        }
        
        return index;
    }
};