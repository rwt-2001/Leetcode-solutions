class Solution {
    int MOD = 1e9 + 7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextMin(n,-1);
        vector<int> prevMin(n,-1);
        
        
        stack<int> stk;
        
        int i = 0;
        
        while(i<nums.size()){

            while(!stk.empty() && nums[stk.top()] > nums[i]){
                nextMin[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
            i++;
        }
        i = nums.size() - 1;
        
        while(i>=0){
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                prevMin[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
            i--;
        }
        
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        long long maxSum = 0;
        for(int i = 0;i<n;i++){
            
            int l = prevMin[i];
            int r = nextMin[i];
            
            // cout<<l<<" "<<r<<endl;
            if(prevMin[i] == -1 && nextMin[i]==-1){
                maxSum = max(maxSum, ((prefix[nums.size()-1]) * nums[i] * 1LL));
            }
         
            maxSum = max(maxSum, (((r!=-1 ? prefix[r-1] : prefix[n-1] )- (l != -1 ? prefix[l] : 0))*1LL * nums[i] * 1LL));
        }
        
        return maxSum%MOD;
    }
};