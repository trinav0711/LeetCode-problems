class Solution {
private:
    vector<vector<int>> ans;
    void bt(vector<int>& nums, int last_idx, set<int>& s, int cur, vector<int>& tmp) {
        if(cur>=nums.size()) {
            ans.push_back(tmp);
            return;
        }
        auto s1=s;
        for(auto idx:s) {
            if(cur && nums[cur-1]==nums[cur] && idx<last_idx)
                continue;
            tmp[idx]=nums[cur];
            s1.erase(idx);
            bt(nums, idx, s1, cur+1, tmp);
            s1.insert(idx);
            tmp[idx]=-100;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp (nums.size(), -100);
        set<int> s;
        for(int i=0;i<nums.size();++i)
            s.insert(i);
        bt(nums, -1, s, 0, tmp);
        return ans;
    }
};