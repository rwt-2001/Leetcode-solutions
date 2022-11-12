class MedianFinder {
    priority_queue<int> leftheap;
    priority_queue<int, vector<int>, greater<int>> rightheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftheap.push(num);
        
        if(leftheap.size() - rightheap.size() > 1){      
            rightheap.push(leftheap.top());
            leftheap.pop();
        }else if(rightheap.size() != 0 && leftheap.top() > rightheap.top()){
            int rt = rightheap.top();
            rightheap.pop();
            rightheap.push(leftheap.top());
            leftheap.pop();
            leftheap.push(rt);
        }
        
        
    }
    
    double findMedian() {
        if(leftheap.size() == rightheap.size()){
            return (double)(leftheap.top() + rightheap.top()) / 2.0;
        }
        
        return leftheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */