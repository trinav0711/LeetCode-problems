class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        queue<pair<int,int>> q;
        int min=0;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(grid[i][j]==1)
                    ++fresh;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        cout<<"fresh="<<fresh<<endl;
        while(!q.empty() && fresh>0) {
            int s=q.size();
            while(s--) {
                auto& [i,j]=q.front();
                if(i && grid[i-1][j]==1) {
                    --fresh;
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(i<grid.size()-1 &&grid[i+1][j]==1) {
                    --fresh;
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j && grid[i][j-1]==1) {
                    --fresh;
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j<grid[0].size()-1 && grid[i][j+1]==1) {
                    --fresh;
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                q.pop();
            }
            ++min;
        }
        return fresh<=0? min:-1;
    }
};