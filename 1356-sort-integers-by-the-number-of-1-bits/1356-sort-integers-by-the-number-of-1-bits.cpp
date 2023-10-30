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
        
        
        map<int,int> cache;
        sort(arr.begin(),arr.end(),[&](int a, int b)
             {
                 int bitA;
                 if(cache[a])
                 {
                    bitA = cache[a]; 
                 }else{
                     bitA = countBit(a);
                     cache[a] = bitA;
                 }
                 int bitB;
                 
                 if(cache[b])
                 {
                    bitB = cache[b]; 
                 }else{
                     bitB = countBit(b);
                     cache[b] = bitB;
                 }
                 
                 if(bitA == bitB) return a < b;
                 return bitA < bitB;
             });
        
        return arr;
    }
};