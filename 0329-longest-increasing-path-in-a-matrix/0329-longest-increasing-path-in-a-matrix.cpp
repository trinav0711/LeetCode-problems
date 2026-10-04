class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i=0;i<matrix.size();++i) {
            for(int j=0;j<matrix[0].size();++j) {
                if(dp[i][j]>0)
                    continue;
                dp[i][j]=1;
                queue<pair<int,int>> q;
                vector<pair<int,int>> dir{{0,1}, {1,0}, {-1,0}, {-0,-1}};
                q.push({i,j});
                while(!q.empty()) {
                    auto [r,c]=q.front(); q.pop();
                    for(auto& p:dir) {
                        int x=p.first+r, y=p.second+c;
                        if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size())
                            continue;
                        if(matrix[x][y]>matrix[r][c] && dp[r][c]+1>dp[x][y]) {
                            dp[x][y]=dp[r][c]+1;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(auto& v:dp)
            ans=max(ans, *max_element(v.begin(), v.end()));
        return ans;
    }
};