class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        vector<int> parents(accounts.size());
        for(int i=0;i<parents.size();++i)
            parents[i]=i;
        function<int(int)> find=[&](int i) {
            if(parents[i]==i) return i;
            return parents[i]=find(parents[i]);
        };
        auto combine=[&](int i, int j) {
            int root1=find(i);
            int root2=find(j);
            if(root1!=root2)
                parents[root1]=root2;
        };
        for(int i=0;i<accounts.size();++i) {
            for(int j=1;j<accounts[i].size();++j) {
                if(m.find(accounts[i][j])!=m.end()) {
                    combine(i, m[accounts[i][j]]);
                }
                else
                    m[accounts[i][j]]=i;
            }
        }
        m.clear();
        unordered_map<int, set<string>> visit;
        for(int i=0;i<parents.size();++i) {
            int cur=find(i);
            for(int idx=1;idx<accounts[i].size();++idx)
                visit[cur].insert(accounts[i][idx]);
        }
        vector<vector<string>> ans;
        for(auto& [idx, v]:visit) {
            vector<string> tmp{accounts[idx][0]};
            for(auto& str:v) tmp.push_back(str);
            ans.push_back(tmp);
        }
        return ans;
    }
};