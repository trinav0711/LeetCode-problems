class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),INT_MAX));
        vector<pair<int,int>> dir {{0,1}, {1,0}, {-1,0},{0,-1}};
        queue<pair<int,int>> q;
        dp[0][0]=grid[0][0];
        q.push({0,0});
        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for(auto& p:dir) {
                int x=r+p.first, y=c+p.second;
                if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
                    continue;
                if(dp[x][y] > max(grid[x][y], dp[r][c])) {
                    dp[x][y] = max(grid[x][y], dp[r][c]);
                    q.push({x,y});
                }
            }
        }
        return dp.back().back();
    }
};