class Solution {
private:
    int dfs(int src, vector<bool>& v, unordered_map<int, set<int>>& m) {
        int ans=0;
        v[src]=1;
        for(int to:m[src]) {
            if(!v[abs(to)]) {
                ans+=(dfs(abs(to), v, m));
                if(to>0)
                    ++ans;
            }
        }
        return ans;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, set<int>> m;
        vector<bool> visit(n, 0);
        for(auto& v:connections) {
            m[v[0]].insert(v[1]);
            m[v[1]].insert(-v[0]);
        }
        return dfs(0, visit, m);
    }
};