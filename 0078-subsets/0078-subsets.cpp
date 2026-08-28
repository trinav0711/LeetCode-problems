class Solution {
private:
    vector<vector<int>> ans;
    void _find(vector<int>& cur, vector<int>& nums, int idx) {
        if(idx>=nums.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        _find(cur, nums, idx+1);
        cur.pop_back();
        _find(cur, nums, idx+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        _find(cur, nums, 0);
        return ans;
    }
};