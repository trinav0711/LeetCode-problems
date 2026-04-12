class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;
        for(int i=0;i<text1.length();++i) {
            vector<int> tmp(text2.length(), 0);
            dp.push_back(tmp);
        }
        for(int i=0;i<text1.length();++i) {
            for(int j=0;j<text2.length();++j) {
                if(text1[i]==text2[j]) {
                    if(!i || !j)
                        dp[i][j]=1;
                    else
                        dp[i][j]=dp[i-1][j-1]+1;
                }
                else {
                    if(i)
                        dp[i][j]=max(dp[i-1][j], dp[i][j]);
                    if(j)
                        dp[i][j]=max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp.back().back();
    }
};