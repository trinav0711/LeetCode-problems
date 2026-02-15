class Solution {
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        dp.reserve(nums.size());
        dp.push_back(nums[0]);
        if(nums.size()<=1)
            return dp[0];
        dp.push_back(nums[1]);
        for(int i=2;i<nums.size();i++) {
            int m=dp[i-1];
            for(int j=i-2;j>=0;j--)
                m=max(m, dp[j]+nums[i]);
            dp.push_back(m);
        }
        return nums.size()>2?dp[nums.size()-1]:max(dp[0], dp[1]);
    }
};