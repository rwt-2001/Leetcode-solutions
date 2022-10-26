class Solution {
public:
    
    int maxlen(int index, vector<string> &arr, unordered_set<int> st){

        if(index == arr.size()) return 0;
        
        int notPick = maxlen(index+1, arr, st);
        
        int pick = 0;
        int flag = 1;
        for(int i = 0;i<arr[index].size();i++){
            if(st.find(arr[index][i]) != st.end()){
                flag = 0;
                break;
            }
            st.insert(arr[index][i]);
        }
        
        if(flag){
            pick = arr[index].size() + maxlen(index+1, arr, st);
        }
        return max(pick, notPick);
    }
    int maxLength(vector<string>& arr) {
        unordered_set<int> st;
        return maxlen(0 ,arr, st);
    }
};