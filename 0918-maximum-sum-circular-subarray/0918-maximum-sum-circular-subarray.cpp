class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0, maxsum=INT_MIN, minsum=INT_MAX, sum1=0, sum2=0;
        for(int x:nums) {
            sum+=x;
            sum1+=x; sum2+=x;
            maxsum=max(maxsum, sum1);
            minsum=min(minsum, sum2);
            sum1=max(sum1, 0);
            sum2=min(sum2, 0);
        }
        if(sum==minsum) return maxsum;
        return max(sum-minsum, maxsum);
    }
};