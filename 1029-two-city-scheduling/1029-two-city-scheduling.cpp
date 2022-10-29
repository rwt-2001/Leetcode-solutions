class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(),[](auto &v1, auto &v2){
           return v1[0] - v1[1] < v2[0] - v2[1]; 
        });
        int res = 0;
        // cout<<454545;
        for(int i = 0;i<costs.size()/2;i++){
            res += costs[i][0] + (costs[i + costs.size()/2][1]);
        }
        return res;
    }
};