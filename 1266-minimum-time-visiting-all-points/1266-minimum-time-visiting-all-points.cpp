class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        
        for(int i = 1; i < points.size(); i++){
            int px = points[i-1][0];
            int py = points[i-1][1];
            int cx = points[i][0];
            int cy = points[i][1];
            ans += max(abs(px - cx), abs(py - cy));
        }
        
        return ans;
    }
};
