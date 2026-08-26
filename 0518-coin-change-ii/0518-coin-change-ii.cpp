class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount+1);
        dp[0]=1;
        for(int coin:coins) {
            for(int i=coin;i<=amount;++i)
                dp[i]+=dp[i-coin];
        }
        for(auto x:dp) cout<<x<<" ";
        return dp.back();
    }
};