class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxEl = arr[0];
        
        for(auto &num: arr)
        {
            maxEl = max(maxEl, num);
        }
        
        int curEl = arr[0];
        int win = 0;
        
        for(int i = 1 ; i < arr.size(); i++)
        {
            if(curEl > arr[i])
            {
                
                win++;
            }else if(curEl < arr[i])
            {
                curEl = arr[i];
                win = 1;
            }
            
            
            if(win == k || curEl == maxEl) return curEl;
        }
        
        return -1;
    }
};