class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> dp, ans;
        sort(nums.begin(), nums.end());
        dp.push_back(0);
        for(int i=0;i<nums.size();++i)
            dp.push_back(dp.back()+static_cast<long long>(nums[i]));
        for(const int q:queries) {
            auto itr=lower_bound(nums.begin(), nums.end(), q);
            int idx=distance(nums.begin(), itr);
            long long q1=static_cast<long long>(q);
            long long sum=(dp.back()-dp[idx])-static_cast<long long>(nums.size()-idx)*q1;
            sum+=(static_cast<long long>(idx)*q1-(dp[idx]-dp[0]));
            ans.push_back(sum);
        }
        return ans;
    }
};