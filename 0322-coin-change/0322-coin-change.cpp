class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        vector<long>dp; dp.reserve(amount+1);
        int m1=*min_element(coins.begin(), coins.end());
        int m2=*max_element(coins.begin(), coins.end());
        set<int> s;
        if(amount<m1)
            return -1;
        for(int x:coins)
            s.insert(x);
        for(int i=0;i<m1;i++)
            dp.push_back(INT_MAX);
        int i;
        for(i=m1;i<=m2 && i<=amount;i++) {
            if(s.find(i)!=s.end()) {
                dp.push_back(1);
                continue;
            }
            dp.push_back(INT_MAX);
            for(int x:s) {
                if(i-x>=0 && dp[i-x]!=INT_MAX)
                    dp[i]=min(dp[i], 1+dp[i-x]);
            }
        }
        if(i<=m2)
            return dp[amount]==INT_MAX?-1:dp[amount];
        for(i=m2+1;i<=amount;i++) {
            dp.push_back(INT_MAX);
            for(int x:s) {
                if(dp[i-x]!=INT_MAX)
                    dp[i]=min(dp[i], 1+dp[i-x]);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};