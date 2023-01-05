class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        int min_req = 0;
        
        int i = 0;
        int n = points.size();
        while(i < n)
        {
            int j = i+1;
            
            while(j < n && points[j][0] <= points[i][1])
            {
                points[j][1] = min(points[i][1],points[j][1]);
                points[j][0] = max(points[i][0],points[j][0]);
                i = j;
                j++;
            }
            
            min_req++;
            i++;
        }
        return min_req;
    }
};