class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;
        int ans = 2;
        for (int i = 0; i < points.size() - 1;i++){
            for(int j = i + 1; j < points.size() ; j++)
            {
                double slope = points[j][0] != points[i][0] ? (points[j][1] - points[i][1]) / (double) (points[j][0] - points[i][0]) : (points[j][1] - points[i][1]) / DBL_MAX;
                int col = 2;
                for (int p = 0;p<points.size();p++)
                {
                    if(p != i && p!=j)
                    {
                        if((points[j][1]-points[i][1] )* (points[i][0]-points[p][0]) == (points[i][1]-points[p][1])*(points[j][0]-points[i][0] )) col++;
                    }
                }
                ans = max(ans, col);
            }
        }
        return ans;
    }
};