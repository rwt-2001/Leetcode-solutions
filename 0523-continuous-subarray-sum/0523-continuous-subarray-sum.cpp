class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        for(int i = 1;i<nums.size();i++){
            
            nums[i] += nums[i-1];
        }
        
        
        map<int,int> mp;
        mp[0] = -1;
        for(int i = 0;i<nums.size();i++){
            
            
            int needed = nums[i] % k;
            if(mp.count(needed)!=0){
                if(i - mp[needed]>1) return true;
            }
            else
                mp[needed] = i;
            
        }
        
        return false;
    }
};