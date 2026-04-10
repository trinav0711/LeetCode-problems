class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();) {
            if(nums[i]) {
                ++i;
                ++left;
                ans=max(ans, left);
            }
            else {
                int cur=i+1;
                for(++i;i<nums.size() && nums[i];++i);
                ans=max(ans, left+i-cur);
                left=i-cur;
            }
        }
        if(ans==nums.size())
            --ans;
        return ans;
    }
};