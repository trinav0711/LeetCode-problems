class Solution {
private:
    set<vector<int>> ans;
    void bt(vector<int>& nums, vector<int>& cur, int idx) {
        if(idx>=nums.size()) {
            ans.insert(cur); return;
        }
        bt(nums, cur, idx+1);
        cur.push_back(nums[idx]);
        bt(nums, cur, idx+1);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        bt(nums, cur , 0);
        vector<vector<int>> res;
        for(auto& v:ans)
            res.push_back(v);
        return res;
    }
};