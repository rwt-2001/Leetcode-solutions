class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int n = nums.size();    
        int ans = nums.size();
        
        
        vector<int> arr;
        for(auto item : st) arr.push_back(item);
        
        for(int i = 0; i < arr.size(); i++)
        {
            int left = arr[i];
            
            int right = arr[i] + n - 1;
            
            int index = upper_bound(arr.begin(), arr.end(), right) - arr.begin();
            
            ans = min(ans, n - (index - i));
            
            
        }
        
        return ans;
        
        
    }
};