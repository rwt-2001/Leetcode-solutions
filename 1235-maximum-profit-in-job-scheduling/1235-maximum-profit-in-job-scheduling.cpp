class Solution {
    vector<int> dp;
public:
    int bs(int l, int r, vector<vector<int>> &arr, int num){
        
        
        int ans = arr.size();
        while(l <= r)
        {
            int mid = (l+r)/2; 
            if(num > arr[mid][0])
            {
                
                l = mid+1;
            }else{
                ans = mid;
                r = mid-1;
        }
        }
        
        return ans;
    }
    int solve(vector<vector<int>> &arr, int index)
    {
        
        if(index==arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int notPick = solve(arr, index + 1);
        int pick = 0;
        int ii = bs(index, arr.size()-1, arr, arr[index][1]);
        
      
        if(index!=arr.size()){
            pick =  solve(arr, ii);
        }
        
        
        
        return dp[index] = max(arr[index][2] + pick, notPick);
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>> arr;
        dp = vector<int> (s.size(), -1);
        for(int i = 0; i < p.size(); i++)
        {
            arr.push_back({s[i], e[i], p[i]});
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        return solve(arr, 0);
    }
};