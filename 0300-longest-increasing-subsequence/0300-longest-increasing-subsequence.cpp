class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            for(int j=i-1;j>=0;j--) {
                if(nums[i]>nums[j] && dp[i]<dp[j]+1) {
                    dp[i]=dp[j]+1;
                }
            }
            m=max(m, dp[i]);
            cout<<dp[i]<<" ";
        }
        return m;
    }
};