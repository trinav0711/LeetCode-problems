class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        for(int i=0;i<grid.size();i++) {
            vector<int> tmp;
            for(int j=0;j<grid[i].size();j++)
                tmp.push_back(INT_MAX);
            dp.push_back(tmp);
        }
        
        dp[0][0]=grid[0][0];
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(j)
                    dp[i][j]=min(dp[i][j], dp[i][j-1]+grid[i][j]);
                if(i)
                    dp[i][j]=min(dp[i][j], dp[i-1][j]+grid[i][j]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};