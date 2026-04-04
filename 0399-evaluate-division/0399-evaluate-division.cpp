class Solution {
private:
    double found;
    void dfs(unordered_map<string, vector<pair<string, double>>>& m, string& source, string& target, set<string>& visit, double p) {
        if(source==target) {
            found=p;
            return;
        }
        for(auto& [t, value]:m[source]) {
            if(found!=DBL_MIN)
                break;
            if(!visit.count(t)) {
                visit.insert(t);
                dfs(m, t, target, visit, p*value);
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<pair<string, string>> n;
        unordered_map<string, vector<pair<string, double>>> e;
        unordered_set<string> nodes;
        for(int i=0;i<equations.size();++i) {
            auto f=equations[i][0], s=equations[i][1];
            nodes.insert(f); nodes.insert(s);
            if(s==f)
                continue;
            if(!n.count({f,s}))
                e[f].push_back({s,values[i]});
            n.insert({f,s});
            if(!n.count({s,f}))
                e[s].push_back({f, 1/values[i]});
            n.insert({s,f});
        }
        vector<double> ans;
        for(auto& v:queries) {
            if(!nodes.count(v[0]) || !nodes.count(v[1])) {
                ans.push_back(-1);
                continue;
            }
            found=DBL_MIN;
            set<string> tmp;
            dfs(e, v[0], v[1], tmp, 1);
            ans.push_back(found!=DBL_MIN?found:-1);
        }
        return ans;
    }
};