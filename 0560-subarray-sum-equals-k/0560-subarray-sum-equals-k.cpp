class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> dp;
        dp.push_back(0);
        for(int x:nums) {
            dp.push_back(dp.back()+x);
        }
        unordered_map<int, int>m;
        ++m[0];
        int ans=0;
        for(int i=1;i<dp.size();++i) {
            int target=dp[i]-k;
            if(m.find(target)!=m.end())
                ans+=m[target];
            ++m[dp[i]];
        }
        return ans;
    }
};