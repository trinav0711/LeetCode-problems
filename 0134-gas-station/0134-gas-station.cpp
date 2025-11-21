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
        int suffix[n];
        suffix[n-1]=gas[n-1]-cost[n-1];
        int maxIdx=n-1;
        for(int i=n-2;i>=0;i--){
            suffix[i]=gas[i]-cost[i]+suffix[i+1];
            if(suffix[i]>suffix[maxIdx])
                maxIdx=i;
        }
        return maxIdx;
    }
};