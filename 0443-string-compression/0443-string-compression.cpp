class Solution {
public:
    int compress(vector<char>& arr) {
        int i = 0;
        int j = 0;
        
        int k = 0;
        while(i < arr.size())
        {
            while(j < arr.size() && arr[i]==arr[j]) j++;
            
            arr[k++] = arr[i];
            int len = j - i;
            
            if(len > 1)
            {
                string lenS = to_string(len);
                for(auto c : lenS) {
                    arr[k++] = c;
                }
            }
            
            i = j;
            j++;
        }
        
        return k;
    }
};