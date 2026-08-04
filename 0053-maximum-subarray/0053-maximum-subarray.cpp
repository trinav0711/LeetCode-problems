class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> sum(nums.size());
        int minn=0, ans=0, maxx=INT_MIN;
        for(int i=0;i<nums.size();++i) {
            sum.push_back((sum.empty()?0:sum.back())+nums[i]);
            if(sum.back()-minn>ans) ans=sum.back()-minn;
            if(sum.back()<minn) minn=sum.back();
            maxx=max(maxx, nums[i]);
        }
        if(maxx<=0) return maxx;
        return ans;
    }
};