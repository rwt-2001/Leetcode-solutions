class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        int i = 1;
        int index = 0;
        while(k)
        {
            if(index<arr.size() && i==arr[index]){
                index++;
                i++;
                continue;
            };
            
            k--;
            ans = i;
            i++;
        }
        return ans;
    }
};