class Solution {
private:
    int dfs(int curr, const vector<vector<int>>& graph, vector<bool>& visited) {
        visited[curr] = true;
        int count = 1;
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                count += dfs(neighbor, graph, visited);
            }
        }
        return count;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        // Step 1: Build the directed graph
        for (int i = 0; i < n; ++i) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                // Calculate squared Euclidean distance
                long long dx = x1 - x2;
                long long dy = y1 - y2;
                long long distSq = dx * dx + dy * dy;

                // If bomb i can detonate bomb j
                if (distSq <= r1 * r1) {
                    graph[i].push_back(j);
                }
            }
        }

        // Step 2: Try detonating each bomb and find the maximum chain reaction
        int max_detonated = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            max_detonated = max(max_detonated, dfs(i, graph, visited));
        }

        return max_detonated;
    }
};