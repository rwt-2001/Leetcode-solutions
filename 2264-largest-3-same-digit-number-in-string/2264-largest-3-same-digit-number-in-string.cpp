class Solution {
public:
    string largestGoodInteger(string num) {
        
        string ans = "";
        int big = 0;
        for(int i = 1; i < num.size() - 1; i++)
        {
            if(num[i - 1] == num[i] && num[i] == num[i+1])
            {
                string  temp = num.substr(i-1,3);
                int tempNum  = stoi(temp);
                if(tempNum >= big)
                {
                    big = tempNum;
                    ans = temp;
                }
            }
        }
        return ans;
    }
};