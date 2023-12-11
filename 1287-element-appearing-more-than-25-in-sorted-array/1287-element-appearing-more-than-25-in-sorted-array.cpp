class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        int ans = arr[0];
        for(int i = 0; i < arr.size(); i++)
        {
            
            int index = upper_bound(arr.begin(), arr.end(), arr[i]) - arr.begin() - 1;
            // cout<<i<<" "<<index<<endl;
            if(arr[index] == arr[i])   
            {
                
                if(index - i + 1 > n/4){
                        
                    ans  = arr[i];
                    break;
                }
                else{
                    i = index;
                }
            }
        }
        
        return ans;
    }
};