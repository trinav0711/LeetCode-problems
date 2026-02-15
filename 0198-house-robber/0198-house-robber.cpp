class Solution {
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        dp.reserve(nums.size());
        dp.push_back(nums[0]);
        if(nums.size()<=1)
            return dp[0];
        dp.push_back(max(nums[1], nums[0]));
        for(int i=2;i<nums.size();i++) 
            dp.push_back(max(dp[i-1], nums[i]+dp[i-2]));
        return dp[nums.size()-1];
    }
};