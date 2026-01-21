class Solution {
public:
    void itrCells(pair<int,int>p, set<pair<int,int>>&s1, int &r,int &c){
        s1.erase(p);
        int i=p.first, j=p.second;
        if(i&&s1.count({i-1,j})){
            s1.erase({i-1,j});
            itrCells({i-1,j},s1,r,c);
        }
        if(j&&s1.count({i,j-1})){
            s1.erase({i,j-1});
            itrCells({i,j-1},s1,r,c);
        }
        if(i<r-1&&s1.count({i+1,j})){
            s1.erase({i+1,j});
            itrCells({i+1,j},s1,r,c);
        }
        if(j<c-1&&s1.count({i,j+1})){
            s1.erase({i,j+1});
            itrCells({i,j+1},s1,r,c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int,int>> s;
        int ctr=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1')
                    s.insert({i,j});
            }
        }
        set<pair<int,int>>s1(s);
        for(auto it=s.begin();it!=s.end();it++){
            if(!s1.count(*it))
                continue;
            ctr++;
            itrCells(*it,s1,m,n);
        }
        return ctr;
    }
};