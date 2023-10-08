class Solution {
    vector<vector<vector<int>>> dp;
public:
    int f(vector<int> &n1, vector<int> &n2, int i, int j, int picked)
    {
        if(i >= n1.size() || j >= n2.size())
        {
            if(picked) return 0;
            return -2000001;
        }
        if(dp[i][j][picked] != -1) return dp[i][j][picked];
        int ans = -2000001;
        
        ans = max({ans, (n1[i]* n2[j]) + f(n1, n2, i+1, j+1, 1), f(n1, n2, i+1 , j, picked), f(n1, n2, i, j+1, picked), f(n1, n2, i + 1, j + 1, picked) });
        return dp[i][j][picked] = ans;
        
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp = vector<vector<vector<int>>>(nums1.size(),vector<vector<int>>(nums2.size(), vector<int>(2, -1)));
        return f(nums1, nums2, 0, 0,0);
    }
};