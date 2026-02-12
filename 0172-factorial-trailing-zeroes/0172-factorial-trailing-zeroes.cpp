class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0 || n<5)
            return 0;
        vector<int> dp;
        dp.reserve(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++) {
            if(i%5) {
                dp[i]=0;
                continue;
            }
            dp[i]=1;
            dp[i]+=dp[i/5];
        }
        int sum=0;
        for(int i=1;i<=n;i++)
            sum+=dp[i];
        return sum;
    }
};