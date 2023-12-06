class Solution {
public:
    int totalMoney(int n) {
                int i = 1;
        int totalWeek = n / 7;
        int leftDays = n % 7;
        int ans = 0;
        if(totalWeek)
        {
            int ft = 28;
            int n = totalWeek;
            int lt = ft + (n - 1)*7;
            ans+= (lt+ft)*n/2;
        }
        
        if(leftDays)
        {
            int ft = totalWeek + 1;
            int lt = ft+leftDays - 1;
            ans += (ft+lt)*leftDays/2;
        }
        
        return ans;
    }
};