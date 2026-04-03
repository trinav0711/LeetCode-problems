class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start, end, flip;
        int ans=0;
        for(start=end=flip=0;end<nums.size();++end) {
            if(nums[end])
                ans=max(ans, end-start+1);
            else {
                if(flip<k) {
                    ++flip;
                    ans=max(ans, end-start+1);
                }
                else {
                    while(nums[start]) ++start;
                    ++start;
                }
            }
        }
        return ans;
    }
};