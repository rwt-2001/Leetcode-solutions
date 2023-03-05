class Solution {
public:
    bool f(int cur_index, vector<int> &arr)
    {
        if(cur_index >= arr.size() || cur_index<0 || arr[cur_index] == -1) return false;
        if(arr[cur_index]==0) return true;
        int cur_val = arr[cur_index];
        arr[cur_index] = -1;
        return f(cur_index + cur_val, arr) || f(cur_index - cur_val, arr); 
    }
    bool canReach(vector<int>& arr, int start) {
        
        return f(start, arr);
    }
};