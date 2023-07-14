class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        map<int,int> mp;
        
        int ans = 1;
        for(int i = 0; i < arr.size(); i++)
        {
            int num = arr[i] - d;
            if(mp[num])
            {
                mp[arr[i]] = max(mp[arr[i]], mp[num] + 1); 
            }else{
                mp[arr[i]] = 1;
            }
            ans = max(mp[arr[i]],ans);
        }
        return ans;
    }
};