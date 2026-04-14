class Solution {
private:
    int f(int i, int j, string& w1, string& w2, vector<vector<int>>& dp) {
        if(i==-1)
            return j+1;
        if(j==-1)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(w1.at(i)==w2.at(j))
            ans=f(i-1, j-1, w1, w2, dp);
        else
            ans=1+min({f(i-1, j, w1, w2, dp), f(i, j-1, w1, w2, dp), f(i-1, j-1, w1, w2, dp)});
        dp[i][j]=ans;
        return ans;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return f(word1.length()-1, word2.length()-1, word1, word2, dp);
    }
};