class Solution {
private:
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
    
    bool isSimilar(string& s1, string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return diff == 0 || diff == 2;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        // Optimization: if n is very large and unique strings are fewer, 
        // we can deduplicate, but standard O(N^2) works well for typical constraints.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    unite(i, j);
                }
            }
        }
        
        int groups = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                groups++;
            }
        }
        return groups;
    }
};