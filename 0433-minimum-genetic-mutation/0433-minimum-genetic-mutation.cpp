class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> mp;
        
        for(auto &m : bank){
            mp[m] = 1;
        }
        
        vector<char> validGene ({'A', 'C', 'G', 'T'});
        
        
        queue<string> q;
        q.push(start);
        int ans = 0;
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i = 0;i<n;i++){
                string curGene = q.front();
                q.pop();
                if(curGene == end) return ans;
                
                for(int j = 0;j<8;j++){
                    char puranaChar = curGene[j];
                    for(int g = 0;g<4;g++){
                        if(validGene[g] == curGene[j]) continue;
                        curGene[j] = validGene[g];
                        
                        if(mp[curGene]){
                            q.push(curGene);
                            mp[curGene] = 0;
                        }
                        curGene[j] =  puranaChar;
                    }
                    
                }
                
                
                
            }
            
        
            ans++;
        }
        
        return -1;
        
    }
};