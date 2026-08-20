class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, -1e9)));
        dp[0][0][0]=0;
        dp[0][0][1]=-prices[0];
        for(int i=1;i<prices.size();++i) {
            for(int k=0;k<3;++k) {
                dp[i][k][0]=dp[i-1][k][0];
                if(k)
                    dp[i][k][0]=max(dp[i][k][0], dp[i-1][k-1][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1], dp[i-1][k][0]-prices[i]);
            }
        }
        return max({dp[prices.size()-1][0][0], dp[prices.size()-1][1][0], dp[prices.size()-1][2][0]});
    }
};