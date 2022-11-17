class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> mp(32);
        int n = 0;
        for(long long num: nums){
            int index = 0;
            if(num < 0){
                num = abs(num);
                n++;
            }
            while(num){
                if(num&1){
                    mp[index]++;
                }
                index++;
                num>>=1;
            }
        }
        
        long long ans = 0;
        int index = 0;
        
        for(int i = 0;i<=31;i++){
            int one = mp[i]%3;
            
            ans  = (ans | (one<<i));
        }
        return n%3 ? -ans : ans;       
    }
};