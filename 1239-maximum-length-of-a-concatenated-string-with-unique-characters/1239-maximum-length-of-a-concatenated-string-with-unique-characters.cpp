class Solution {
public:
    int solve(vector<string>&arr,int index,string formed){
        if(index>=arr.size()){
           return formed.size();
        }
        
        
        int ans = 0;
         map<int,int> mp;
        for(auto &cc: formed){
            mp[cc]++;
        }
        
            bool flag = false;
            map<int,int> temp;
            for(auto &cc: arr[index]){
                if(mp[cc] || temp[cc]){
                    flag = true;
                    break;
                }
                temp[cc]++;
                
            }
            
            if(!flag){
                ans = max(ans, solve(arr, index + 1, formed + arr[index]));
            }
            
            ans = max(ans, solve(arr, index + 1, formed));
        
        
        return ans;
        
    }
    int maxLength(vector<string>& arr) {
        return solve(arr,0, "");
    }
};