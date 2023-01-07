class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;
        int ans = 0;
        int total = 0;
        int i = 0;
        while(i < gas.size()){
            
            total += gas[i] - cost[i];
            gasSum += gas[i];
            costSum += cost[i];
            if(total < 0){
                ans = i+1;
                total = 0;
            }
            i++;
            
        }
        return gasSum < costSum ? -1 : ans;                                         
                                                                    
    }
};