class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int> mpN;
        map<int,int> mpS;
        
        for(int i = 0;i<nums.size();i++){
            mpN[nums[i]] = 1;
            mpS[nums[i]%space]++;
        }
        
        int ans = nums[0];
        int maxFreq = -1;
        
        for(auto &val : mpN){
            int n = val.first;
            if(mpS[n%space] > maxFreq){
                ans = n;
                maxFreq = mpS[n%space] ;
            }
        }
        
        return ans;
    }
};