class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                int top = r-1 >= 0 ? matrix[r-1][c] : 0;
                int left = c-1 >=0 ? matrix[r][c-1]: 0;
                int diagonal = (r-1 >= 0 && c-1 >= 0) ? matrix[r-1][c-1] : 0;
                matrix[r][c] = matrix[r][c] + top + left - diagonal;
            }
        }
        
        int ans = 0;
        for(int startRow = 0; startRow < rows; startRow++)
        {
            for(int startCol = 0; startCol < cols; startCol++)
            {
                for(int c = startCol; c < cols; c++)
                {
                    for(int r = startRow; r< rows; r++)
                    {
                        int sum = matrix[r][c];
                        int top = startRow - 1 >= 0 ? matrix[startRow-1][c] : 0;
                        int left = startCol - 1 >= 0 ? matrix[r][startCol - 1] : 0;
                        int diagonal = (startCol - 1 >= 0 &&  startRow - 1>=0) ? matrix[startRow - 1][startCol - 1] : 0;
                        if(target == (sum - top - left + diagonal)) ans++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};

