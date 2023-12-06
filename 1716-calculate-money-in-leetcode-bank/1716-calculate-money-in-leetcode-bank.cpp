class Solution {
public:
    int totalMoney(int n) {
        int i = 1;
        int totalWeek = n / 7;
        int leftDays = n % 7;
        int ans = 0;
        while(totalWeek)
        {
            int ft = i;
            int lt = i+6;
            ans += (ft+lt)*7/2;
            i++;
            totalWeek--;
        }
        
        if(leftDays)
        {
            int ft = i;
            int lt = i+leftDays - 1;
            ans += (ft+lt)*leftDays/2;
        }
        
        return ans;
    }
};