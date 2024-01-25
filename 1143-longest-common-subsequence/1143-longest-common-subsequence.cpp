class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        vector<int> prev(n, 0);
        vector<int> cur(n,0);
        
        
        for(int i = 0; i < text2.size(); i++)
        {
            for(int j = 0; j < n; j++){
                
                if(text1[j] == text2[i]){
                    if(i == 0 || j==0){
                        cur[j] = 1;
                    }else{
                        cur[j] = prev[j-1] + 1;
                    }
                }else{
                    if(j > 0){
                        cur[j] = max(cur[j - 1], prev[j]);
                    }else{
                        cur[j] = prev[j];
                    }
                }
                
            }
            
            prev = cur;
        }
        
        return cur[n-1];
    }
};