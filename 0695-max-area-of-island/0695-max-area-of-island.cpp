class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(grid[i][j]==1) {
                    int tot=0;
                    queue<pair<int,int>> q; q.push({i,j});
                    grid[i][j]=2;
                    while(!q.empty()) {
                        auto [x,y]=q.front(); q.pop(); ++tot;
                        if(x && grid[x-1][y]==1) {
                            grid[x-1][y]=2; q.push({x-1,y});
                        }
                        if(x<grid.size()-1 && grid[x+1][y]==1) {
                            grid[x+1][y]=2; q.push({x+1,y});
                        }
                        if(y && grid[x][y-1]==1) {
                            grid[x][y-1]=2; q.push({x, y-1});
                        }
                        if(y<grid[0].size()-1 && grid[x][y+1]==1) {
                            grid[x][y+1]=2; q.push({x,y+1});
                        }
                    }
                    ans=max(ans, tot);
                }
            }
        }
        return ans;
    }
};