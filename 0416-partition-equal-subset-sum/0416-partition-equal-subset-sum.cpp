class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums) sum+=x;
        if(sum%2) return false;
        sum/=2;
        vector<bool> dp(sum+1, false);
        dp[0]=true;
        for(int x:nums) {
            for(int i=sum;i>=x;--i) {
                dp[i]=dp[i]||dp[i-x];
                if(dp[sum]) return true;
            }
        }
        return dp.back();
    }
};