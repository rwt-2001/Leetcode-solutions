class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i = 0; i < colors.size()-1; i++)
        {
            if(colors[i]==colors[i+1])
            {
                
                priority_queue<int,vector<int>,greater<int>> mh;
                char c = colors[i];
                int j = i;
                while(j<colors.size() && colors[j]==c)
                {
                    mh.push(neededTime[j++]);
                }
                
                while(mh.size() > 1)
                {
                    ans += mh.top();
                    mh.pop();
                }
                i = j-1;
            }
        }
        
        return ans;
    }
};


