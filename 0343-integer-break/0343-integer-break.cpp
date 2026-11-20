class Solution {
public:
    int integerBreak(int n) {
        int ans=1;
        vector<int> dp(n+1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;++i) {
            for(int j=1;j<i;++j) {
                dp[i]=max(dp[i], j*max(i-j, dp[i-j]));
            }
        }
        for(int i=0;i<n;++i) cout<<dp[i]<<endl;
        return dp.back();
    }
};