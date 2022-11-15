class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        
        int i = 0;
        
        while(i<str.size()){
            int j = i+1;
            char mx = str[i];
            int index = 0;
            while(j < str.size()){
                if(str[j] >= mx){
                    index = j;
                    mx = str[j];
                }
                j++;
            }
            if(mx!=str[i]){
                cout<<mx<<endl;
                swap(str[index], str[i]);
                return stoi(str);
            }
            
            i++;
        }
        
        return stoi(str);
    }
};