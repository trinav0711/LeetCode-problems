class Solution {
private:
    int dfs(int start, const string& s, const unordered_set<string>& dict, vector<int>& memo) {
        int n = (int)s.size();
        if (start >= n) {
            return 0;
        }
        if (memo[start] != -1) {
            return memo[start];
        }

        // Option 1: treat s[start] as an extra character
        int best = 1 + dfs(start + 1, s, dict, memo);

        // Option 2: match a dictionary word starting at `start`
        for (int end = start; end < n; ++end) {
            string sub = s.substr(start, end - start + 1);
            if (dict.count(sub)) {
                best = min(best, dfs(end + 1, s, dict, memo));
            }
        }

        return memo[start] = best;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> memo(s.size(), -1);
        return dfs(0, s, dict, memo);
    }
};