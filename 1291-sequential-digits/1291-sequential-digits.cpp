class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        int ls = to_string(low).size();
        int hs = to_string(high).size();
        vector<int> ans;
        for(int curSz = ls; curSz <= hs; curSz++)
        {
            
            for(int i = 0; i + curSz <= str.size(); i++)
            {
                string curStr= str.substr(i, curSz);
           
                int curNum = stoi(curStr);
                if(curNum > high) break;
                if(curNum >= low && curNum <= high)
                {
                    ans.push_back(curNum);
                }
            }
            
        }
        
        return ans;
    }
};