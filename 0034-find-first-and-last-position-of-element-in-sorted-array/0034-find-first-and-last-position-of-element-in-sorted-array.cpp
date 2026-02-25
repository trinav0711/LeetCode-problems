class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itr=lower_bound(nums.begin(), nums.end(), target);
        if(itr==nums.end() || *itr!=target)
            return {-1, -1};
        auto itr2=upper_bound(nums.begin(), nums.end(), target)-1;
        return {int(itr-nums.begin()), int(itr2-nums.begin())};
    }
};