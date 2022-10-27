class Solution {
public:
    
    int maxlen(int index, vector<string> &arr, vector<int> &mp){

        if(index == arr.size()) return 0;
        
        int notPick = maxlen(index+1, arr, mp);
        
        int pick = 0;
        int flag = 1;
        for(int i = 0;i<arr[index].size();i++){
            if(mp[arr[index][i] - 'a']){
                flag = 0;
                for(int j = 0;j<i;j++){
                    mp[arr[index][j] - 'a']--;
                }
                break;
            }
            mp[arr[index][i]-'a']++;
        }
        
        if(flag){
            pick = arr[index].size() + maxlen(index+1, arr, mp);
            for(int j = 0;j<arr[index].size();j++){
                mp[arr[index][j] - 'a']--;
            }
        }
        return max(pick, notPick);
    }
    int maxLength(vector<string>& arr) {
        
        vector<int> mp(26);
        return maxlen(0 ,arr, mp);
        
    }
};