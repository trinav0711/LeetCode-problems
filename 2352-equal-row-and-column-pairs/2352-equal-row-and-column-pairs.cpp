class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        for(int i=0;i<grid.size();++i) {
            vector<int> tmp;
            for(int j=0;j<grid[i].size();j++)
                tmp.push_back(grid[i][j]);
            if(rows.find(tmp)==rows.end())
                rows[tmp]=1;
            else
                ++rows[tmp];
        }
        int ans=0;
        for(int j=0;j<grid[0].size();++j) {
            vector<int> tmp;
            for(int i=0;i<grid.size();++i)
                tmp.push_back(grid[i][j]);
            if(rows.find(tmp)!=rows.end())
                ans+=(rows[tmp]);
        }
        return ans;
    }
};