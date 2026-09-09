class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int,int>>> m;
        for(auto& v:edges) {
            m[v[0]].push_back({v[1], v[2]});
            m[v[1]].push_back({v[0], v[2]});
        }
        pair<int, int> ans {-1, INT_MAX};
        queue<int> q;
        vector<int> dist(n, INT_MAX);
        while(n--) {
            q.push(n); int reach=0;
            for(int i=0;i<dist.size();++i) dist[i]=INT_MAX;
            dist[n]=0;
            while(!q.empty()) {
                auto cur=q.front(); q.pop();
                for(auto& p:m[cur]) {
                    if(dist[cur]+p.second<=distanceThreshold &&
                            dist[cur]+p.second<dist[p.first]) {
                        dist[p.first]=dist[cur]+p.second;
                        q.push(p.first);
                    }
                }
            }
            for(int x:dist)
                if(x && x<INT_MAX) ++reach;
            if(reach<ans.second) {
                ans.first=n; ans.second=reach;
            }
        }
        return ans.first;
    }
};