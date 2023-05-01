class Solution {
public:
    double average(vector<int>& salary) {
        int mins = INT_MAX;
        int maxs = INT_MIN;
        double ans = 0;
        
        for(auto a: salary){
            if(mins > a)
            {
                mins = a;
            }
            
            if(maxs < a)
            {
                maxs = a;
            }
            
            ans += a;
        }
        
        
        return (ans - mins - maxs) / (salary.size() - 2);
    }
};