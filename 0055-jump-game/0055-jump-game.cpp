class Solution {
public:
    bool canJump(vector<int>& nums) {
        int indexAchievable = 0;
        int sz = nums.size();
        for(int i = 0;i<sz;i++){
            if(indexAchievable<i) return false;    
            indexAchievable = max(indexAchievable,i+nums[i]);
        }
        return true;
        
    }
    
    
//Tab 
// int dp[nums.size()];
//         int sz = nums.size();
//         dp[0] = 1;
        
//         for(int i = 0;i<sz;i++){
//             if(dp[i]==1){
//                 int jumps = nums[i];
//                 for(int j = i+1; j<= i+jumps;j++){
//                     if(j==sz-1) return true;
//                     if(j>=sz) break;
//                     dp[j] = 1;
//                 }
//             }
//         }
        
//         return dp[sz-1]==1;
//Memo ----> TLE
//     bool canReach(vector<int> nums, int index, int dp[]){
//         if(index > nums.size()-1) return false;
//         if(dp[index]!=-1) return dp[index];
//         if(index == nums.size()-1 ) return true;
        

//         int jumps = nums[index];
        
//         for(int i = 1;i<=jumps;i++){
//             bool reached = canReach(nums,index+i,dp);
//             if(reached) {
//                 dp[index] = true;
//                 return true;
//             }
//         }
//         dp[index] = false;
//         return false;
        
        
//     }
};