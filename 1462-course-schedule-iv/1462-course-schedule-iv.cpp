class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> m;
        for(auto& v:prerequisites)
            m[v[1]].push_back(v[0]);
        function<bool(int, int, unordered_set<int>&)> dfs=[&](int cur, int t, unordered_set<int>& visit) {
            if(visit.find(cur)!=visit.end()) return false;
            visit.insert(cur);
            if(cur==t) return true;
            for(auto nei:m[cur]) {
                if(visit.find(nei)==visit.end()) {
                    if(dfs(nei, t, visit)) {
                        return true;
                    }
                }
            }
            return false;
        };
        vector<bool> ans;
        for(auto& v:queries) {
            unordered_set<int> visit;
            ans.push_back(dfs(v[1], v[0], visit));
        }
        return ans;
    }
};