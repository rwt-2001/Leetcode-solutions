class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       
        int ans = 0;
        int len = strs[0].size();
        
        for(int i = 0;i<len; i++){
            
            for(int j = 0;j<strs.size() - 1;j++){
                // cout<<strs[j][i]<<" ";
                if(strs[j][i] > strs[j+1][i]){
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};