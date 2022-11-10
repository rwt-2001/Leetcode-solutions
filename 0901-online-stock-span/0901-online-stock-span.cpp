class StockSpanner {
    stack<pair<int,int>> stk;
    int counter ;
public:
    StockSpanner() {
        counter = 1;
    }
    
    int next(int price) {
        while(!stk.empty() && stk.top().first <= price ){
            stk.pop();
        }
        
        
        
        int ans = 0;
        if(stk.size() >= 1){
            ans = counter - stk.top().second;

        } else{
            ans = counter - 0;
        }
        stk.push({price,counter});
        counter++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */