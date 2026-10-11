class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int, unordered_set<int>> m;
        int ans=1;
        for (int i=0;i<routes.size();++i) {
            for(int stop:routes[i])
                m[stop].insert(i);
        }
        unordered_set<int> visit;
        queue<int> q; q.push(source);
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto cur=q.front(); q.pop();
                for(auto route:m[cur]) {
                    if(visit.find(route)!=visit.end())
                        continue;
                    for(int stop:routes[route]) {
                        if(stop==target)
                            return ans;
                        if(m.find(stop)!=m.end() && stop!=cur) {
                            q.push(stop);
                            m[stop].erase(route);
                        }
                    }
                    visit.insert(route);
                }
                m.erase(cur);
            }
            ++ans;
        }
        return -1;
    }
};