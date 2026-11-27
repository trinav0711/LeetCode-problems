class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        auto func = [&](this auto&& self, int cur) -> int {
            if (dp[cur] != -1) return dp[cur];

            int cnt = INT_MAX;
            for (int j = 1; j * j <= cur; ++j) {
                cnt = min(cnt, 1 + self(cur - j * j));
            }
            return dp[cur] = cnt;
        };

        return func(n);
    }
};