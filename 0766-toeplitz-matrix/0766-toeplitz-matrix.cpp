class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col  = matrix[0].size();
        
        for(int j = col-1;j >= 0;j--){
            int temp = matrix[0][j];
            int curCol = j;
            for(int i = 0;i<row && curCol < col;i++){
                if(temp != matrix[i][curCol++]) return false;
            }
        }
        
        for(int i = row - 1;i >= 0;i--){
            int temp = matrix[i][0];
            int curRow = i;
            for(int j = 0;j < col && curRow < row;j++){
                // cout<<matrix[curRow][j];
                if(temp != matrix[curRow++][j]) return false;
            }
        }
            
        return true;
        
    }
};