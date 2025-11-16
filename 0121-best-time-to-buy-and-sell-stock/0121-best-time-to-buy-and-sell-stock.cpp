class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxIdx=0,minIdx=0,cost=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[minIdx]) minIdx=i;
            else if((i>minIdx)&&(prices[i]-prices[minIdx]>cost)){
                    cost=prices[i]-prices[minIdx];
                    maxIdx=i;
            }
        }
        return cost;
    }
};