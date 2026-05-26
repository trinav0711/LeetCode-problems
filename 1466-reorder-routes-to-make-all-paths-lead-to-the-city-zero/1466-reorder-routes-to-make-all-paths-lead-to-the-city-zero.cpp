class Solution {
private:
    int ans;
    unordered_set<int> nodes;
    unordered_map<int, vector<int>> orig;
    void dfs(unordered_map<int,vector<int>>& m, unordered_set<int>& visit, int cur) {
        visit.insert(cur);
        if(visit.size()<nodes.size()) {
            for(int x:m[cur])
                if(visit.find(x)==visit.end())
                    dfs(m, visit, x);
            for(int x:orig[cur]) {
                if(visit.find(x)==visit.end()) {
                    ++ans;
                    dfs(m, visit, x);
                }
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> m; unordered_set<int> visit;
        for(auto& v:connections) {
            nodes.insert(v[0]); nodes.insert(v[1]);
            m[v[1]].push_back(v[0]);
            orig[v[0]].push_back(v[1]);
        }
        dfs(m, visit, 0);
        if(visit.size()!=nodes.size()) return -1;
        return ans;
    }
};