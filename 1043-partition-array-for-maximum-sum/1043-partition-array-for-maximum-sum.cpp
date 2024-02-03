class Solution {
    vector<int> dp;
public:
    int solve(vector<int> &arr, int index, int &k)
    {
        if(index == arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans = 0;
        int mxEl = 0;
        int cnt = 0;
        for(int i = index; i < arr.size() && i < index + k; i++)
        {
            mxEl = max(arr[i], mxEl);
            cnt++;
            ans = max(ans, (mxEl*cnt) + solve(arr, i+1, k));
        }
        return dp[index] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp = vector<int> (arr.size(), -1);
        return solve(arr, 0, k);
    }
};