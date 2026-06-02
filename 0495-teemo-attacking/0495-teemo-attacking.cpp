class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        for(int i=0, cur=0;i<timeSeries.size();++i) {
            cur=max(cur, timeSeries[i]);
            ans+=(timeSeries[i]+duration-cur);
            cur=max(cur, timeSeries[i]+duration);
        }
        return ans;
    }
};