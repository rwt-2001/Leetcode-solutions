class Solution {
public:
    int countBit(int num)
    {
        int cnt = 0;
        while(num)
        {
            cnt+=num&1;
            num>>=1;
        }
        
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        
        
        sort(arr.begin(),arr.end(),[&](int a, int b)
             {
                 int bitA = countBit(a);
                 int bitB = countBit(b);
                 
                 if(bitA == bitB) return a < b;
                 return bitA < bitB;
             });
        
        return arr;
    }
};