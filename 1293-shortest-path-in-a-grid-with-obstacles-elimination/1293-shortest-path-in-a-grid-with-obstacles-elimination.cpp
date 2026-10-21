class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0]=k;
        vector<pair<int,int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>> q;
        q.push({0,0});
        int steps=0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto [x,y]=q.front(); q.pop();
                if(x==m-1 && y==n-1)
                    return steps;
                for(auto& p:dir) {
                    int r=p.first+x, c=p.second+y;
                    if(r<0 || c<0 || r>=m || c>=n)
                        continue;
                    int rem=dp[x][y]-grid[r][c];
                    if(rem>=0 && (dp[r][c]==-1|| dp[r][c]<rem)) {
                        dp[r][c]=rem;
                        q.push({r,c});
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};