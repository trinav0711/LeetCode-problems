class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 1));
        for(int i=1;i<dp.size();++i) {
            if(arr[i]>arr[i-1])
                dp[i][0]=dp[i-1][1]+1;
            else if(arr[i]<arr[i-1])
                dp[i][1]=dp[i-1][0]+1;
        }
        int ans=INT_MIN;
        for(int i=0;i<dp.size();++i) {
            ans=max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};