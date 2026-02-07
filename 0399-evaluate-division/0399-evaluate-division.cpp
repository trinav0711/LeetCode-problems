class Solution {
    double dfs(map<pair<string,string>,double>& m, map<string, vector<string>>& m1, string& s, string& d) const {
        queue<string>q;
        m[{s,s}]=1;
        if(d==s)
            return 1;
        q.push(s);
        set<string> visit;
        while(!q.empty()) {
            visit.insert(q.front());
            for(string s1:m1[q.front()]) {
                if(visit.find(s1)!=visit.end())
                    continue;
                m[{s, s1}]=m[{s,q.front()}]*m[{q.front(),s1}];
                cout<<"source="<<q.front()<<" and dest="<<s1<<"\n";
                if(s1==d)
                    return m[{s,s1}];
                q.push(s1);
            }
            q.pop();
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<pair<string, string>, double> m;
        set<string> s;
        map<string, vector<string>> m1;
        vector<vector<string>>& eq=equations;
        for(int i=0;i<eq.size(); i++) {
            s.insert(eq[i][0]); s.insert(eq[i][1]);
            m[{eq[i][0], eq[i][1]}]=values[i];
            m[{eq[i][1], eq[i][0]}]=1/values[i];
            m1[eq[i][0]].push_back(eq[i][1]);
            m1[eq[i][1]].push_back(eq[i][0]);
        }
        vector<double> ans;
        for(vector<string> q:queries) {
            if(s.find(q[0])==s.end() || s.find(q[1])==s.end()) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(dfs(m, m1, q[0], q[1]));
        }
        return ans;
    }
};