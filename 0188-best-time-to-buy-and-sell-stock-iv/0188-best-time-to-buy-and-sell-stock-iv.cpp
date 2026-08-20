class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<vector<int>>> dp(prices.size(), 
            vector<vector<int>>(k + 1, 
                vector<int>(2, -1e9)
            )
        );
        dp[0][0][0]=0;
        dp[0][0][1]=-prices[0];
        for(int i=1;i<prices.size();++i) {
            for(int k1=0;k1<=k;++k1) {
                dp[i][k1][0]=dp[i-1][k1][0];
                if(k1)
                    dp[i][k1][0]=max(dp[i][k1][0], dp[i-1][k1-1][1]+prices[i]);
                dp[i][k1][1]=max(dp[i-1][k1][1], dp[i-1][k1][0]-prices[i]);
            }
        }
        auto maxx=dp[prices.size()-1][0][0];
        for(int i=1;i<=k;++i)
            maxx=max(maxx, dp[prices.size()-1][i][0]);
        return maxx;
    }
};