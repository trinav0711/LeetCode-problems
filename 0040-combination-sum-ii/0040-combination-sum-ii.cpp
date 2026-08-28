class Solution {
private:
    set<vector<int>> ans;
    void _find(vector<int>& cand, int tar, vector<int>& cur, int idx) {
        if(idx<0 || idx>=cand.size()) return;
        if(tar-cand[idx]<0) return;
        tar-=cand[idx];
        if(!tar) {
            ans.insert(cur);
            return;
        }
        for(int i=idx+1;i<cand.size();++i) {
            if(tar-cand[i]<0) break;
            if(i > idx + 1 && cand[i] == cand[i-1]) continue;
            cur.push_back(cand[i]);
            _find(cand, tar, cur, i);
            cur.pop_back();
        }
    } 
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        for(int i=0;i<candidates.size();++i) {
            if(target-candidates[i]<0) break;
            if(i && candidates[i]==candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            _find(candidates, target, cur, i);
            cur.pop_back();
        }
        vector<vector<int>> res;
        for(auto& v:ans) res.push_back(v);
        return res;
    }
};