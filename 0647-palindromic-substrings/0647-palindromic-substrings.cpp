class Solution {
private:
    bool isPalin(string& str, int start, int end, vector<vector<bool>>& dp) noexcept {
        if(start<0 || end>=str.length()) return false;
        while(start<end) {
            if(dp[start][end]) break;
            if(str[start++]!=str[end--]) return false;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for(int i=0;i<dp.size();++i) {
            for(int j=i;j>=0;--j)
                dp[i][j]=isPalin(s, j, i, dp);
        }
        int ans=0;
        for(int i=0;i<s.length();++i) {
            for(int j=0;j<s.length();++j)
                if(dp[i][j]) ++ans;
        }
        return ans;
    }
};