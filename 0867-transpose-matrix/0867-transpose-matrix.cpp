class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix[0].size(), vector<int>(matrix.size(), false));
        for(int i=0;i<matrix.size();++i) {
            for(int j=0;j<matrix[0].size();++j) {
                dp[j][i]=matrix[i][j];
            }
        }
        return dp;
    }
};