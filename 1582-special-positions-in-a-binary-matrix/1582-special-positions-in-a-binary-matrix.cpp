class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> ver(mat.size(), 0), hor(mat[0].size());
        
        for(int i = 0; i < mat.size();i++)
        {
            int sum = 0;
            for(int j = 0;j < mat[0].size(); j++)
            {
                sum+=mat[i][j];
            }
            ver[i] = sum;
        }
        for(int i = 0; i < mat[0].size();i++)
        {
            int sum = 0;
            for(int j = 0;j < mat.size(); j++)
            {
                sum+=mat[j][i];
            }
            hor[i] = sum;
        }
        int ans = 0;
        for(int i = 0; i < mat.size();i++)
        {
            
            for(int j = 0;j < mat[0].size(); j++)
            {
                if(mat[i][j] == 1 && hor[j]==1 && ver[i] ==1) ans++;
            }
            
        }
        
        return ans;
    }
};