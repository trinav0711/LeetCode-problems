class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg=0, sumc=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            sumg+=gas[i];
            sumc+=cost[i];
        }
        if(sumc>sumg)
            return -1;
        int suffix=gas[n-1]-cost[n-1];
        int maxIdx=n-1; int suffixMax=suffix;
        for(int i=n-2;i>=0;i--){
            suffix=gas[i]-cost[i]+suffix;
            if(suffix>suffixMax){
                suffixMax=suffix;
                maxIdx=i;
            }
        }
        return maxIdx;
    }
};