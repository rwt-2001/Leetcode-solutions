class MedianFinder {
    priority_queue<double> left;
    priority_queue<double, vector<double> , greater<double>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        
        if(left.size() - right.size() > 1){
            right.push(left.top());
            left.pop();
        }
        if(!right.empty() && left.size() - right.size() == 1 && left.top() > right.top()){
            double temp = left.top();
            left.pop();
            left.push(right.top());
            right.pop();
            right.push(temp);
        }
    }
    
    double findMedian() {
        if(left.size() != right.size()){
           return left.top();
        }
        // cout<<left.top()<<" "<<right.top()<<endl;
        return (left.top() + right.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */