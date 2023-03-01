class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int r){
        vector<int> temp;
        
        int i = l;
        int j = mid+1;
        
        while(i <= mid || j <= r)
        {
            if(i > mid)
            {
                while(j<=r)
                {
                    temp.push_back(nums[j++]);
                }
            }
            else if(j > r)
            {
                while(i<=mid)
                {
                    temp.push_back(nums[i++]);
                }
            }else{
                if(nums[i] < nums[j])
                {
                    temp.push_back(nums[i++]);
                }else{
                    temp.push_back(nums[j++]);
                }
            }
        }
        
        int index = 0;
        while(l<=r)
        {
            nums[l++] = temp[index++];
        }
    }

    void mergeSort(vector<int> &nums, int l, int r)
    {
        if(l==r) return;
        
        int mid = (l + r)/2;
        
        mergeSort(nums,l, mid);
        mergeSort(nums, mid + 1, r);
        
        merge(nums, l ,mid, r);
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};