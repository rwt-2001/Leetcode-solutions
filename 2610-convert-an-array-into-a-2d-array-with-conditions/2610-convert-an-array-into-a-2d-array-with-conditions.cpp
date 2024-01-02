class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = 0;
        map<int,int> mp;
        
        
        while(n < nums.size())
        {
            map<int,int> el;
            vector<int> temp;
            for(int i = 0; i < nums.size();i++)
            {
                if(mp[i]==0 && el[nums[i]] ==0){
                    mp[i]++;
                    el[nums[i]]++;
                    temp.push_back(nums[i]);
                    n++;
                }
            }
            
            ans.push_back(temp);
        }
        
        
        return ans;
    }
};