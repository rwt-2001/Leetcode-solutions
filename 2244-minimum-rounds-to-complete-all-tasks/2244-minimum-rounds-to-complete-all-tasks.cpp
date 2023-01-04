class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        
        for(auto &dif : tasks){
            mp[dif]++;
        }
        
        
        int ans = 0;
        for(auto &m : mp){
            
            int val = m.second;
            // cout<<m.first<<" "<<val<<endl;
            if((val % 3) % 2 == 0){
                ans += (val / 3);
                ans += (val%3)/2;
                continue;
                
            }

            int n = 0;
            while(val > 1){
                val -= 2;
                n++;
                if(val%3 == 0){
                    ans += n + val/3;
                    val = 0;
                    break;
                }
            }
            
            if(val)
            return -1;
            
        }

        
        return ans;
    }
};