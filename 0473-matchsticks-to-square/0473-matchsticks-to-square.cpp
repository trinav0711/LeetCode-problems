class Solution {
private:
    bool dfs(const vector<int>& m, vector<int>& sides, int idx) {
        if (idx == (int)m.size()) {
            return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
        }

        unordered_set<int> tried;
        for (int i = 0; i < 4; ++i) {
            if (m[idx] > sides[i] || tried.count(sides[i])) continue;
            tried.insert(sides[i]);

            sides[i] -= m[idx];
            if (dfs(m, sides, idx + 1)) return true;
            sides[i] += m[idx];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        long long total = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        if (total == 0 || total % 4 != 0) return false;
        long long target = total / 4;
        vector<int> sticks = matchsticks;
        sort(sticks.rbegin(), sticks.rend());
        if (sticks[0] > target) return false;

        vector<int> sides(4, (int)target);
        return dfs(sticks, sides, 0);
    }
};