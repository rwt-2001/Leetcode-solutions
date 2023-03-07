class Solution {
public:
    bool canMakeTrip(long long mid, vector<int> &time, long long tt){
        long long trips = 0;
        for(auto &t : time)
        {
            trips += mid/t;
            if(trips >= tt) return true;
        }
        
        return false;
    }
    long long minimumTime(vector<int>& time, int tt) {
        long long start = 1;
        long long end = LLONG_MAX;
        long long ans = -1;
        
        while(end >= start)
        {
            long long mid = start + (end-start)/2;
            
            if(canMakeTrip(mid, time, tt)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        return ans;
        
    }
};