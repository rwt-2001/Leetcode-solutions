class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            
            int num = nums[i];
            int cnt = 0;
            while(i < nums.size() && nums[i]==num)
            {
                cnt++;
                i++;
            }
            if(cnt==1) return -1;
            
            if(cnt%3 == 0) ans += (cnt / 3);
            else{
                ans += (cnt/3)+ 1;
            }
            i--;
            
            
        }
        return ans;
    }
};