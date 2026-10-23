class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        int m=board.size(),n=board[0].size();
        vector<pair<int,int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        function<void(int,int)> dfs=[&](int i,int j) {
            if(board[i][j]=='.') return;
            board[i][j]='.';
            for(auto& p:dir) {
                int x=i+p.first, y=j+p.second;
                if(x<0 || y<0 || x>=m || y>=n || board[x][y]=='.')
                    continue;
                dfs(x,y);
            }
        };
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(board[i][j]=='X') {
                    ++ans;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
};