class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n-1;
        int j = n-1;
        while(j>=0){
            if(s[j]!=' '){
                i = j;
                while(i>=0 && s[i]!=' '){
                    i--;
                }
                if(i<0 || (i>=0 && s[i]==' ')) i++;
                int temp = i;
                
                while(i<j){
                    swap(s[i], s[j]);
                    j--;
                    i++;
                }
                j = temp-1;
            }
            
            j--;
        }
        i = 0;
        j = n-1;
        while(i<j){
            swap(s[i++], s[j--]);
        }
        i = 0;
        j = 0;
        while(j<n){
            if(s[j]!=' '){
                while(s[j]!=' ' && j<n){
                    s[i++] = s[j++];
                }
                if(i<=n-1);
                    s[i++] = ' ';
            }
            else
                j++;
        }
        while(i<n){
            s[i++] = ' ';
        }
        j = n-1;
        while(j>=0 && s[j] ==' '){
            s.pop_back();
            j--;
        }
        
        return s;
        
    }
};