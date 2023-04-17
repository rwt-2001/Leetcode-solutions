class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mxEl = *max_element(candies.begin(), candies.end());
        
        vector<bool> ans;
        
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= mxEl)
            {
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        
        
        return ans;
    }
};