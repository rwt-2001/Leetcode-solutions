class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int min_avg = INT_MAX;
        int i_avg = -1;
        long long int pre_Sum = 0;
        long long int  post_Sum = 0;
        int sz = nums.size();
        long long int avg_diff;
        for(int i = 0;i<sz;i++)
            post_Sum+=nums[i];
        
        for(int i = 0;i<sz-1;i++){
            
            pre_Sum+=nums[i];
            post_Sum-=nums[i];
            
            avg_diff = abs((pre_Sum/(i+1)) - (post_Sum/(sz-i-1)));
       
            if(avg_diff<min_avg){
                min_avg = avg_diff;
                i_avg = i;
            }
            
        }
        pre_Sum+=nums[sz-1];
        avg_diff = abs((pre_Sum/sz));
        if(avg_diff<min_avg){
                min_avg = avg_diff;
                i_avg = sz-1;
        }
        return i_avg;
        
    }
};