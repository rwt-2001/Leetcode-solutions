class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        
        int end = r*c - 1;
        int start = 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int rr =  mid/c;
            int cc = mid%c;
            // cout<<mid<<" "<<rr<<" "<<cc<<" "<<matrix[rr][cc]<<endl;
            if(matrix[rr][cc] > target)
            {
                end = mid-1;
            }else if(matrix[rr][cc] < target)
            {
                start = mid + 1;
            }
            else{
                return true;
            }
            
            
        }
        
        return false;
    }
};