class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s.back() != '0') return false;

        vector<bool> dp(n, false);
        dp[0] = true;
        int windowReachable = 0;

        for (int i = 1; i < n; ++i) {
            // Index (i - minJump) enters the valid jump window
            if (i >= minJump && dp[i - minJump]) {
                ++windowReachable;
            }
            // Index (i - maxJump - 1) leaves the valid jump window
            if (i > maxJump && dp[i - maxJump - 1]) {
                --windowReachable;
            }
            // Index i is reachable if it is '0' and at least one index in the window is reachable
            if (s[i] == '0' && windowReachable > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};