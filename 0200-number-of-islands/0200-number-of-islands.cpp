class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<pair<int,int>> dir{{0,1}, {1,0}, {0,-1},{-1,0}};
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(grid[i][j]=='1') {
                    ++ans;
                    queue<pair<int,int>> q; q.push({i,j});
                    while(!q.empty()) {
                        auto [r,c]=q.front(); q.pop();
                        for(auto& p:dir) {
                            int x=p.first+r, y=p.second+c;
                            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]=='0')
                                continue;
                            grid[x][y]='0';
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        return ans;
    }
};