class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> adj(n);
        
        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // For each node, keep only the top 3 neighbors with the highest scores
        for (int i = 0; i < n; ++i) {
            sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
                return scores[a] > scores[b];
            });
            if (adj[i].size() > 3) {
                adj[i].resize(3);
            }
        }
        
        int maxScore = -1;
        
        // Iterate over every edge (B, C) as the middle edge
        for (auto& edge : edges) {
            int b = edge[0];
            int c = edge[1];
            
            // Try combinations of top neighbors A (for b) and D (for c)
            for (int a : adj[b]) {
                if (a == c) continue; // A cannot be C
                
                for (int d : adj[c]) {
                    if (d == b || d == a) continue; // D cannot be B or A
                    
                    maxScore = max(maxScore, scores[a] + scores[b] + scores[c] + scores[d]);
                }
            }
        }
        
        return maxScore;
    }
};