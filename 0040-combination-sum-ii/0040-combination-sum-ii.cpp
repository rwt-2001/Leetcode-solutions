class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> dummy;
        formCombination(candidates,target,0, dummy);
        return result;
    }
    
    void formCombination(vector<int> &candidates, int target, int n,vector<int> &dummy){

        
        if(target==0){
            result.push_back(dummy);
            return;
        }
       
        if(target<0 || n == candidates.size()) return;
        
        int lastPick = -1;
        
        for(int i = n;i<candidates.size();i++){
                if(lastPick!=candidates[i]){
                    dummy.push_back(candidates[i]);
                    formCombination(candidates,target-candidates[i], i+1, dummy);
                    dummy.pop_back(); 
                    lastPick = candidates[i];
                }
                
            
        }
        
    }
};