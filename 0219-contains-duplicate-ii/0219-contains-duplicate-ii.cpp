class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[nums[0]] = -1;
        
        for(int i = 1;i<nums.size();i++){
            if(mp[nums[i]]){
                if(mp[nums[i]]==-1){
                    if(i - 0 <= k) return true;
                }else{
                     if(i - mp[nums[i]] <= k) return true;
                } 
            }
            mp[nums[i]] = i;
            
            
        }
        
        return false;
    }
};