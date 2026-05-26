class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(!grid[i][j]) continue;
                if(!i) ++ans;
                if(!j) ++ans;
                if(i==grid.size()-1) ++ans;
                if(j==grid[0].size()-1) ++ans;
                if(j && !grid[i][j-1]) ++ans;
                if(j<grid[0].size()-1 && !grid[i][j+1]) ++ans;
                if(i && !grid[i-1][j]) ++ans;
                if(i<grid.size()-1 && !grid[i+1][j]) ++ans;
            }
        }
        return ans;
    }
};