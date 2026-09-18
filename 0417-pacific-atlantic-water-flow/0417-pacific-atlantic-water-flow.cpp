class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& dp, int i, int j, int mask) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        
        // If this cell already has this mask applied, we've visited it for this ocean. Stop.
        if ((dp[i][j] & mask) == mask) return;
        
        // Apply the mask (adds 1 for Atl, 2 for Pac. If it has both, it becomes 3)
        dp[i][j] |= mask;
        
        // Explore 4 directions independently. 
        // Only flow to neighbors if their height is >= current cell (water flows down to ocean)
        if (i > 0 && heights[i-1][j] >= heights[i][j]) dfs(heights, dp, i-1, j, mask);
        if (i < heights.size()-1 && heights[i+1][j] >= heights[i][j]) dfs(heights, dp, i+1, j, mask);
        if (j > 0 && heights[i][j-1] >= heights[i][j]) dfs(heights, dp, i, j-1, mask);
        if (j < heights[0].size()-1 && heights[i][j+1] >= heights[i][j]) dfs(heights, dp, i, j+1, mask);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> dp(heights.size(), vector<int>(heights[0].size(), 0));
        
        int m = heights.size();
        int n = heights[0].size();
        
        // 1 = Atlantic (Right and Bottom edges)
        for(int j = 0; j < n; ++j) dfs(heights, dp, m-1, j, 1);
        for(int i = 0; i < m; ++i) dfs(heights, dp, i, n-1, 1);
        
        // 2 = Pacific (Top and Left edges)
        for(int j = 0; j < n; ++j) dfs(heights, dp, 0, j, 2);
        for(int i = 0; i < m; ++i) dfs(heights, dp, i, 0, 2);
        
        vector<vector<int>> ans;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // If it reached both, its mask will be 1 | 2 = 3
                if(dp[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};