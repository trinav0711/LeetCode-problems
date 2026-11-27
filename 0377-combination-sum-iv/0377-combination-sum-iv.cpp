class Solution {
private:
    int bt(const vector<int>& nums, int t, unordered_map<int, int>& m) const {
        if(!t) return 1;
        if(m.find(t)!=m.end())
            return m[t];
        for(int i=0;i<nums.size();++i) {
            if(t-nums[i]>=0)
                m[t]+=bt(nums, t-nums[i], m);
            else
                break;
        }
        return m[t];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        bt(nums, target, m);
        return m[target];
    }
};