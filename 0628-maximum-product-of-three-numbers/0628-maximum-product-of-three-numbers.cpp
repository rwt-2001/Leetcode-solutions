class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for(auto &num : nums)
        {
            //handles max
            
            if(num > max1){
                
                max3 = max2;
                max2 = max1;
                max1 = num;
                
            }else if(num > max2)
            {
                max3 = max2;
                max2 = num;
            }else if(num > max3){
                max3 = num;
            }
            
            //handles min
            if(num < min1)
            {
                min2 = min1;
                min1 = num;
                
            }else if(num < min2)
            {
                min2 = num;
            }
            
            
        }
        
        cout<<max1<<" "<<max2<<" "<<max3<<" ";
        return max(min1*min2*max1,max1 * max2 * max3);
    }
};