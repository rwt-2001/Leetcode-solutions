class BrowserHistory {
public:
    stack<string> undo;
    stack<string> redo;
    BrowserHistory(string homepage) {
        undo.push(homepage);
    }
    
    void visit(string url) {
        undo.push(url);
        while(redo.size()) redo.pop();
    }
    
    string back(int steps) {
        string cur_page;
        while(steps-- && undo.size() > 1)
        {
            cur_page = undo.top();
            undo.pop();
            redo.push(cur_page);
        }
        return undo.top();
    }
    
    string forward(int steps) {
        string cur_page;
        while(steps-- && redo.size() > 0)
        {
             cur_page = redo.top();
             redo.pop();
             undo.push(cur_page);
        }
        
        return undo.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */