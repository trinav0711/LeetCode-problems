class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(), nums.end());
        int right=accumulate(nums.begin(), nums.end(), 0);
        while(left<right) {
            int sum=0, segs=1;
            int mid=(left+right)/2;
            for(int x:nums) {
                if(x+sum>mid) {
                    sum=x; ++segs;
                }
                else sum+=x;
            }
            if(segs>k) left=mid+1;
            else right=mid;
        }
        return left;
    }
};