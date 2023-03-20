class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        for(int i = 0; i < fb.size() && n > 0; i++)
        {
            if(fb[i]==0 && (i-1 >= 0 ? fb[i-1]==0 : 1) && (i+1 <fb.size() ? fb[i+1]==0 : 1))
            {
                n--;
                i++;
            }
            if(n <= 0) return true;
        }
        
        return n<=0;
    }
};