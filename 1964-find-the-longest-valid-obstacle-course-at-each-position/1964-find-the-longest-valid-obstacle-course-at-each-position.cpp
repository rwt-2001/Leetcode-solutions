class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        vector<int> lis;
        vector<int> ans;
        
        for(auto &num: arr)
        {
            if(lis.size() > 0 && lis.back() > num)
            {
                int index = upper_bound(lis.begin(), lis.end(), num) - lis.begin();
                
                lis[index] = num;
                ans.push_back(index+1);
            }else{
                lis.push_back(num);
                ans.push_back(lis.size());
            }
        }
        
        return ans;
    }
};