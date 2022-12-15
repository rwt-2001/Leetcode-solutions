class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.size();
        int sz2 = text2.size();
        
        int arr[sz1+1][sz2+1];
        for(int i = 0;i<sz2+1;i++)
            arr[0][i] = 0;
        for(int i = 0;i<sz1+1;i++)
            arr[i][0] = 0;
        
        for(int i = 1;i<sz1+1;i++){
            for(int j = 1;j<sz2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    arr[i][j] = 1 + arr[i-1][j-1];
                }
                else{
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                    
                }
            }
        }
        return arr[sz1][sz2];
    }
};