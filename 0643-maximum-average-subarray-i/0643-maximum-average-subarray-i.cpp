class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        volatile int sum=0;
        double ans=INT_MIN;
        for(int i=0;i<nums.size() && i<k;++i)
            sum+=nums[i];
        ans=max(ans, double(sum));
        for(int i=1;i+k<=nums.size();++i) {
            sum=sum-nums[i-1]+nums[i+k-1];
            ans=max(ans, (double)sum);
        }
        return ans/k;
    }
};