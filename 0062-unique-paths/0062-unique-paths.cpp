class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        for(int i=0;i<m;++i) {
            vector<int> tmp;
            for(int j=0;j<n;++j)
                tmp.push_back(0);
            dp.push_back(tmp);
        }
        dp[0][0]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j) {
                if(j)
                    dp[i][j]+=dp[i][j-1];
                if(i)
                    dp[i][j]+=dp[i-1][j];
            }
        }
        return dp.back().back();
    }
};