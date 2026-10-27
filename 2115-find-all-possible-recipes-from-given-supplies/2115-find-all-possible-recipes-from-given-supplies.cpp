class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> edge;
        unordered_map<string, int> cnt;
        for(int i=0;i<recipes.size();++i) {
            cnt[recipes[i]]=ingredients[i].size();
            for(const auto& str:ingredients[i])
                edge[str].push_back(recipes[i]);
        }
        queue<string> q;
        for(const auto& sup:supplies) {
            q.push(sup);
            if(cnt.find(sup)!=cnt.end())
                cnt.erase(sup);
        }
        while(!q.empty()) {
            auto cur=q.front(); q.pop();
            if(edge.find(cur)==edge.end())
                continue;
            for(const auto& nei:edge[cur]) {
                --cnt[nei];
                if(!cnt[nei]) {
                    q.push(nei);
                    cnt.erase(nei);
                }
            }
        }
        vector<string> ans;
        for(const auto& str:recipes) {
            if(cnt.find(str)==cnt.end()) {
                ans.push_back(str);
            }
        }
        return ans;
    }
};