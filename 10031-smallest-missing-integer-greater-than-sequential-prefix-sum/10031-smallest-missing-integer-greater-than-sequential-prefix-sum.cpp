class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int,int> mp;
        int sum = nums[0];
        mp[nums[0]]++;
        int flag = true;
        
        for(int i = 1; i < nums.size(); i++){
            
            if(flag && nums[i] == nums[i-1]+1)
            {
                sum += nums[i];
            }else{
                flag = false;
            }
            
            
            mp[nums[i]]++;
        }
        int leastNum = sum;
        while(mp[leastNum])
        {
            leastNum++;
        }
        
        return leastNum;
        
    }
};