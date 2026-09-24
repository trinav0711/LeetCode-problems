class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int i;
        vector<int> ans; ans.reserve(nums.size()-k+1);
        for(i=0;i<nums.size()&&i<k;++i)
            s.insert(nums[i]);
        ans.push_back(*s.rbegin());
        for(i;i<nums.size();++i) {
            s.insert(nums[i]);
            s.erase(s.find(nums[i-k]));
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};