class Solution {
    set<int> visit;
    bool dfs(set<int>& s, const int n, unordered_map<int, vector<int>> &m) {
        visit.erase(n);
        for(int x:m[n]) {
            if(s.find(x)!=s.end())
                return false;
            s.insert(x);
            if(visit.find(x)==visit.end() && !dfs(s, x, m))
                return false;
            s.erase(x);
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        set<int> s;
        for(int i=0;i<numCourses;i++) {
            m[i]={};
            visit.insert(i);
        }
        for(vector<int>&v:prerequisites) {
            if(v[0]==v[1])
                return false;
            m[v[1]].push_back(v[0]);
        }
        while(!visit.empty()) {
            int n=*visit.begin();
            if(visit.find(n)==visit.end())
                continue;
            cout<<n<<"\n";
            set<int> tmp={n};
            if(!dfs(tmp, n, m))
                return false;
        }
        return true;
    }
};