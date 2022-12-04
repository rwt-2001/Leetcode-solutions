class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long tSum = 0;
        for(auto &num  : nums) tSum += num;
        long long iSum = 0;
        int n = nums.size();
        
        int minAvg = INT_MAX;
        int index = -1;
        for(int i = 0;i<n ; i++){
            tSum -= nums[i];
            iSum += nums[i];
            // cout<<i+1 << " "<<nums.size() -1 -i<<endl;
            int avg = abs( int(iSum / (i + 1)) - ((n - 1 - i != 0) ? int(tSum / (n - 1 - i)) : 0));
            if(avg < minAvg){
                index = i;
                minAvg = avg;
            }
        }
        
        return index;
        
    }
};