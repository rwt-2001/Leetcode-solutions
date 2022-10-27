class Solution {
public:
    int getCounts(vector<vector<int>> &img1, vector<vector<int>> &img2, int shiftX, int shiftY)
    {
        
        int mxOverlap = 0;
        int n = img1.size();
        for(int row = shiftX; row < n; row++){
            for(int col = shiftY; col < n; col++){
                mxOverlap += img1[row][col] * img2[row - shiftX][col - shiftY];
            }
        }
        
        return mxOverlap;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int ans = 0;
        int n = img1.size();
        for(int row = 0; row<n; row++){
            for(int col = 0; col < n; col++){
                ans = max(ans, getCounts(img1, img2, row, col));
                ans = max(ans, getCounts(img2, img1, row, col));
            }
        }
        reverse(img1.begin(), img1.end());
        reverse(img2.begin(), img2.end());
        for(int row = 0; row<n; row++){
            for(int col = 0; col < n; col++){
                ans = max(ans, getCounts(img1, img2, row, col));
                ans = max(ans, getCounts(img2, img1, row, col));
            }
        }
        return ans;
        
    }
};