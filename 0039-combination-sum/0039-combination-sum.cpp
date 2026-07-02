class Solution {
private:
    void recur(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& cand, int t, int cur) {
        if(!t) {
            ans.push_back(tmp);
            return;
        }
        for(int i=cur;i>=0;--i) {
            if(t-cand[i] < 0) continue;
            tmp.push_back(cand[i]);
            recur(ans, tmp, cand, t-cand[i], i);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        recur(ans, tmp, candidates, target, candidates.size()-1);
        return ans;
    }
};