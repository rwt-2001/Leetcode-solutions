class Solution {
public:
    int numSquares(int n) {
        
        
        int lmt = sqrt(n);
        vector<int> rootN;
        vector<int> dp(n+1, -1);
        for(int i = 1;i<=lmt;i++){
            rootN.push_back(i*i);
        }
        
        queue<int> q;
        
        
        q.push(n);
        int steps = 0;
        while(q.size() != 0){
            int n = q.size();
            
            for(int i=0;i<n;i++){
                int curT = q.front();
                q.pop();
                if(curT== 0) return steps;
                for(auto &num : rootN){
                    
                    if(curT-num < 0 || dp[curT-num] != -1) continue;
                  
                    q.push(curT-num);
                    dp[curT-num] = 1;
                    
                }
                
            }
            
            
            steps++;
        }
        
        return 0;
    }
};