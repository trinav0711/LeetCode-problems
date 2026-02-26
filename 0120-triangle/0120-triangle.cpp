class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for(int i=0;i<triangle.size();i++) {
            vector<int> tmp;
            for(int j=0;j<triangle[i].size();j++)
                tmp.push_back(INT_MAX);
            dp.push_back(tmp);
        }
        dp[0][0]=triangle[0][0];
        for(int i=1;i<dp.size();i++) {
            for(int j=0;j<dp[i].size();j++) {
                if(j)
                    dp[i][j]=min(dp[i][j], dp[i-1][j-1] + triangle[i][j]);
                if(j<dp[i-1].size())
                    dp[i][j]=min(dp[i][j], dp[i-1][j] + triangle[i][j]);
            }
        }
        int m=INT_MAX;
        for(int j=0;j<dp[dp.size()-1].size();j++)
            m=min(m, dp[dp.size()-1][j]);
        return m;
    }
};