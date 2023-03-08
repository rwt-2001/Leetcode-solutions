class Solution {
public:
    bool canEat(vector<int> &piles, int h, int k){
        long long int hr = 0;
        for(auto bn : piles){
            
            hr = (hr + ((bn%k==0) ? bn/k : bn/k +1));
            
            if(hr > h) return false;
        }
        // cout<<k<<" "<<hr<<" "<<h<<endl;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;
        
        while(start <= end)
        {
            int mid = start + (end- start)/2;
            if(canEat(piles, h, mid))
            {
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
            
        }
        
        return ans;
    }
};


