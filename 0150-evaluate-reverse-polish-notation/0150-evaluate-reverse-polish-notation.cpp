class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        int i = 0;
        while(i < tokens.size())
        {
            string curToken = tokens[i++];
            
            if(curToken == "+")
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1 + num2);
            }else if(curToken == "-"){
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1 - num2);
            }else if(curToken == "*")
            {
                 int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1 * num2);
            }else if(curToken == "/")
            {
                 int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1 / num2);
            }else{
                stk.push(stoi(curToken));
            }
        }
        
        return stk.top();
    }
};