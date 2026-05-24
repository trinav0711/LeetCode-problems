class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mis, dup;
        mis=dup=1;
        for(int i=1;i<nums.size();++i) {
            if(nums[i]==nums[i-1]) dup=nums[i];
            else if(nums[i]>nums[i-1]+1) mis=nums[i]-1;
        }
        if(nums.back()!=nums.size()) mis=nums.size();
        return {dup, mis};
    }
};