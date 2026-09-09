class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(n, vector<int>(k+1, INT_MAX));
        unordered_map<int, vector<pair<int, int>>> list;
        for(auto& v:flights) {
            list[v[0]].push_back({v[1], v[2]});
        }
        queue<pair<int,int>> q;
        q.push({src, 0});
        for(int j=0;j<=k;++j) dp[src][j]=0;
        while(!q.empty()) {
            auto [cur,stop]=q.front(); q.pop();
            if(stop>k) continue;
            for(auto& [n,w]:list[cur]) {
                if(stop==k) {
                    if(dst==n)
                        dp[n][stop]=min(dp[n][stop], dp[cur][stop]+w);
                }
                else {
                    if(dp[n][stop+1]==INT_MAX || dp[n][stop+1]>dp[cur][stop]+w) {
                        dp[n][stop+1]=dp[cur][stop]+w;
                        q.push({n, stop+1});
                    }
                }
            }
        }
        int maxx=INT_MAX;
        for(int j=0;j<=k;++j) maxx=min(maxx, dp[dst][j]);
        if(maxx==INT_MAX) return -1;
        return maxx;
    }
};