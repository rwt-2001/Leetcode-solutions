class Solution {
public:
    map<pair<int,int>, bool> dp;
    bool solve(vector<int> &stones, int i, int lastJump, int k)
    {
        if(i == stones.size()-1){
            return lastJump == stones[i];
        }
        if(dp.count({k, lastJump})) return  dp[{k, lastJump}];
        
        if(lastJump < stones[i]) return false;
        if(lastJump > stones[i])
        {
            return solve(stones, i + 1, lastJump, k);
        }
        
        if(solve(stones, i + 1, lastJump + k, k)) return true;
        if(solve(stones, i + 1, lastJump + k + 1, k + 1)) return true;
        if(k-1 && solve(stones, i + 1, lastJump + k - 1, k - 1)) return true;
        dp[{k, lastJump}] = false;
        return false;
    }
    bool canCross(vector<int>& stones) {
        
        return solve(stones,1,1,1);
    }
};