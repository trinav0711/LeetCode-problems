class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> pre, suf;
        int mi=INT_MAX;
        for(int i=0;i<nums.size();i++) {
            pre.push_back(mi);
            mi=min(mi, nums[i]);
        }
        reverse(nums.begin(), nums.end());
        for(int i=0, mi=INT_MIN;i<nums.size();i++) {
            suf.push_back(mi);
            mi=max(mi, nums[i]);
        }
        reverse(nums.begin(), nums.end());
        reverse(suf.begin(), suf.end());
        for(int i=0;i<nums.size();i++) {
            if(pre[i]<nums[i] && nums[i]<suf[i])
                return true;
        }
        return false;
    }
};