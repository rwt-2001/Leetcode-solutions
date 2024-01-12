class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        
        int area = 0;
        double maxLen = 0;
        for(int i = 0; i < d.size(); i++)
        {
            if(maxLen <= sqrt(((double)d[i][0]*d[i][0]) + (d[i][1]*d[i][1])))
            {
                if(maxLen == sqrt(((double)d[i][0]*d[i][0]) + (d[i][1]*d[i][1])))
                {
                     area =  max(area, d[i][0] * d[i][1]);
                }
                else {maxLen = sqrt(((double)d[i][0]*d[i][0]) + (d[i][1]*d[i][1])); area = d[i][0] * d[i][1];}
               
            }
        }
        return area;
    }
};