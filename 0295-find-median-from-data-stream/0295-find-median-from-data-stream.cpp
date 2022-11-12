class MedianFinder {
    priority_queue<double> maxpq;
    priority_queue<double, vector<double>, greater<double>> minpq;
public:
    MedianFinder() {
        //Jai shree Ram
    }
    
    void addNum(int num) {
        maxpq.push(num);
        
        if(maxpq.size() - minpq.size() > 1){

            minpq.push(maxpq.top());
            maxpq.pop();
        }
        if(minpq.size()!=0 && minpq.top() < maxpq.top()){
                int minitop = minpq.top();
                int maxtop = maxpq.top();
                minpq.pop();
                maxpq.pop();
                maxpq.push(minitop);
                minpq.push(maxtop);
            }
    }
    
    double findMedian() {
        if(maxpq.size() == minpq.size()){
            // cout<<maxpq.top() + minpq.top()<<endl;
            double med = (maxpq.top() + minpq.top())/2.0;
            return med;
        }
        // cout<<maxpq.size()<<" "<<minpq.size()<<endl;
        return maxpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */