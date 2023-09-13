class Solution {
public:
    int candy(vector<int>& r) {
        int ans = r.size();
        
        int index = 1;
        
        while(index < r.size())
        {
            while(index < r.size() && r[index - 1]==r[index]) index++;
            
            int hill = 0;
            
            while(index < r.size() && r[index - 1]<r[index])
            {
                hill++;
                ans += hill;
                index++;
            }
            
            int valley = 0;
            while(index < r.size() && r[index - 1]>r[index])
            {
                valley++;
                ans += valley;
                index++;
            }
            
            ans -= min(valley, hill);
        }
        
        
        return ans;
    }
};