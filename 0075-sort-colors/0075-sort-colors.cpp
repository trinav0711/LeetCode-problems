class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty() || nums.size()==1) return;
        for(int left=0, right=nums.size()-1;left<right;) {
            if(nums[left]!=2)
                ++left;
            else {
                if(nums[right]!=2) {
                    int tmp=nums[right];
                    nums[right]=2;
                    nums[left]=tmp;
                }
                --right;
            }
        }
        int right=0;
        while(right<nums.size() && nums[right]!=2) ++right;
        --right;
        for(int left=0;left<right;) {
            if(nums[left]==0)
                ++left;
            else {
                if(nums[right]!=1) {
                    int tmp=nums[right];
                    nums[right]=1;
                    nums[left]=tmp;
                }
                --right;
            }
        }
    }
};