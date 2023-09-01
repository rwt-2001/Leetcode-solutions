class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        for(int i = 0;i<=n; i++)
        {
            int setb = 0;
            int n = i;
            while(n)
            {
                setb += n&1;
                n = n>>1;
            }
            
            ans.push_back(setb);
        }
        
        return ans;
    }
};