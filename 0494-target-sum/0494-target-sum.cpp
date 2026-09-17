class Solution {
private:
    int ans;
    void bt(vector<int>& nums, int idx, int t) {
        if(idx==nums.size()) {
            if(!t) ++ans;
            return;
        }
        bt(nums, idx+1, t+nums[idx]);
        bt(nums, idx+1, t-nums[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        ans=0;
        bt(nums, 0, target);
        return ans;
    }
};