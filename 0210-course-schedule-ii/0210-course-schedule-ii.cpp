class Solution {
private:
    set<int> visit;
    stack<int> st;
    bool traverse(vector<int>& v, int cur, unordered_map<int, vector<int>>& m,
        set<int>& s) {
        visit.erase(cur);
        for(int x:m[cur]) {
            if(s.find(x)!=s.end())
                return false;
            if(visit.find(x)!=visit.end()) {
                s.insert(x);
                if(!traverse(v, x, m, s))
                    return false;
                s.erase(x);
            }
        }
        st.push(cur);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for(int i=0;i<numCourses;i++) {
            m[i]={};
            visit.insert(i);
        }
        vector<vector<int>> ans;
        for(vector<int>& v:prerequisites)
            m[v[1]].push_back(v[0]);
        while(!visit.empty()) {
            vector<int> tmp;
            set<int> tmp1={*visit.begin()};
            if(!traverse(tmp, *visit.begin(), m, tmp1))
                return {};
            ans.push_back(tmp);
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};