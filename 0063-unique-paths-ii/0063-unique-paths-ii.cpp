class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp;
        for(int i=0;i<m;i++) {
            vector<int> tmp;
            for(int j=0;j<n;j++)
                tmp.push_back(0);
            dp.push_back(tmp);
        }
        dp[0][0]=1-obstacleGrid[0][0];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(obstacleGrid[i][j])
                    continue;
                if(i)
                    dp[i][j]+=dp[i-1][j];
                if(j)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};