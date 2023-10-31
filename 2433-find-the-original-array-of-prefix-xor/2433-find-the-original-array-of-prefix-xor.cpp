class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        vector<int>ans;
        
        ans.push_back(arr[0]);
        
        for(int i = 1; i<arr.size(); i++)
        {
            ans.push_back(arr[i-1] ^ arr[i]);
        }
        return ans;
    }
};