class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int> mp;
        int n = nums.size();
        mp[nums[0]] = -1;
        
        for(int i = 1;i<n;i++){
            
            if(mp[nums[i]] != 0){
                if(i - (mp[nums[i]] < 0 ? 0 : mp[nums[i]]) <= k) return true;

            }
            mp[nums[i]] = i;
            
        }
        
        return false;
        
    }
};