class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = 1;i<n;i++){
            nums[i] += nums[i-1];
        }
        map<int,int> mp;
        mp[0]=-1;
        for(int i = 0;i<n;i++){
            
            int modK = nums[i] % k;
            if(mp.find(modK) != mp.end()){
                
                if(i - mp[modK]>1) return true;
            }
            else{
                mp[modK] = i;
            }
        }
        
        return false;
        
    }
};