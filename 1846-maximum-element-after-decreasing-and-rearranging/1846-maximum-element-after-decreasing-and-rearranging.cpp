class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int pos = 0;
        int ans = pos;
        for(int i = 0; i < arr.size() ; i++)
        {
            if(arr[i] == pos) continue;
            if(arr[i] > pos)
            {
                pos = pos + 1;
                ans = max(pos, ans);
            }
        }
        return ans;
    }
};


