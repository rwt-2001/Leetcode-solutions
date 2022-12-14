class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> mp;
        for(auto &val : words){
            mp[val]++;
        }
        
        
        int flag = 0;
        
        int ans = 0;
        for(int i = 0;i<words.size();i++){
            string curStr = words[i];
            
            string revStr = words[i];
            reverse(revStr.begin(), revStr.end());
            
            int minF = min(mp[curStr], mp[revStr]);
            
            if(curStr == revStr && minF > 1 ){
                if(minF & 1) minF--;
                
                ans += (2*minF);
                mp[curStr] -= minF;
            }
            
            else if(curStr != revStr){
                ans += (4*minF);
                mp[curStr] -= minF;
                mp[revStr] -= minF;
            }
            else if(curStr == revStr && minF == 1 && !flag){
                ans += 2;
                flag = 1;
            }
        }

        return ans;
    }
};