class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.empty()) return 0;
        int row=heights.size(), col=heights[0].size();
        if(row==1 && col==1) return 0;
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        dp[0][0]=0;
        vector<pair<int, int>> dir {{0,1}, {1,0}, {-1,0}, {0,-1}};
        queue<pair<int,int>> q; q.push({0,0});
        while(!q.empty()) {
            auto [r,c]=q.front(); q.pop();
            for(auto& p:dir) {
                int x=p.first+r, y=p.second+c;
                if(x<0 || x>=row) continue;
                if(y<0 || y>=col) continue;
                if(dp[x][y]==INT_MAX || dp[x][y]>max(dp[r][c], abs(heights[x][y]-heights[r][c]))) {
                    dp[x][y]=max(dp[r][c], abs(heights[x][y]-heights[r][c]));
                    q.push({x,y});
                }
            }
        }
        if(dp[row-1][col-1]==INT_MAX) return -1;
        return dp[row-1][col-1];
    }
};