class Solution {
private:
    set<vector<int>> ans;
    void dfs(int k, int n, vector<int>& s) {
        if(!k && n)
            return;
        if(!n && k)
            return;
        if(!k && !n) {
            sort(s.begin(), s.end());
            ans.insert(s);
        }
        for(int i=(s.empty()?1:s.back()+1);i<=min(9,n);++i) {
            s.push_back(i);
            --k; n-=i;
            dfs(k, n, s);
            s.pop_back();
            n+=i; ++k;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> s;
        dfs(k, n, s);
        vector<vector<int>> res;
        for(auto& tmp:ans)
            res.push_back(tmp);
        return res;
    }
};