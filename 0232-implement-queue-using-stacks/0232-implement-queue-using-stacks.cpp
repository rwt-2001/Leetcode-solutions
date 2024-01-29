class MyQueue {
    stack<int> stk1, stk2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(stk1.size())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.push(x);
        while(stk2.size())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    int pop() {
       int ans = stk1.top();
        stk1.pop();
        return ans;
    }
    
    int peek() {
        return stk1.top();
    }
    
    bool empty() {
        return stk1.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */