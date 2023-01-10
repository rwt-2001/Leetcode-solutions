class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> maxHeap;
        
        for(auto num : nums)
        {
            maxHeap.push(num);
        }
        
        long long ans = 0;
        
        while(k)
        {
            long long val = maxHeap.top();
            ans += val ;
            maxHeap.pop();
            maxHeap.push(ceil(val/(double)3));
            k--;
        }
 
        return ans;
    }
};