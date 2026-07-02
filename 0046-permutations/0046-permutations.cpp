class Solution {
private:
    void recur(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums, set<int>& s,
        int cur) {
            if(s.empty() && cur==nums.size()) {
                ans.push_back(tmp);
                return;
            }
            set<int> newidx(s);
            for(int idx:newidx) {
                tmp[idx]=nums[cur++];
                s.erase(idx);
                recur(ans, tmp, nums, s, cur);
                s.insert(idx);
                --cur;
            }
        }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        set<int> idx;
        vector<int> tmp{nums};
        for(int i=0;i<nums.size();++i) idx.insert(i);
        recur(ans, tmp, nums, idx, 0);
        return ans;
    }
};