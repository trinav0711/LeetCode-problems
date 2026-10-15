class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> dp(height.size());
        for(int i=0, maxx=0; i<height.size();++i) {
            maxx=max(maxx, height[i]);
            dp[i]=maxx;
        }
        for(int i=height.size()-1, maxx=0;i>=0;--i) {
            maxx=max(maxx, height[i]);
            dp[i]=min(dp[i], maxx);
        }
        int ans=0;
        for(int i=0;i<height.size();++i) {
            ans+=(max(0, dp[i]-height[i]));
        }
        return ans;
    }
};