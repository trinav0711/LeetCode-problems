class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edge;
        vector<int> ans(n+1, -1);
        for(auto& v:times) {
            edge[v[0]].push_back({v[1], v[2]});
        }
        queue<int> q; q.push(k);
        ans[k]=0;
        while(!q.empty()) {
            int cur=q.front(); q.pop();
            for(auto& [n,w]:edge[cur]) {
                if(ans[n]==-1 || ans[n]>ans[cur]+w) {
                    ans[n]=ans[cur]+w;
                    q.push(n);
                }
            }
        }
        int maxx=INT_MIN;
        for(int i=1;i<ans.size();++i) {
            if(ans[i]==-1) { cout<<i<<endl; return -1;}
            maxx=max(maxx, ans[i]);
        }
        return maxx;
    }
};