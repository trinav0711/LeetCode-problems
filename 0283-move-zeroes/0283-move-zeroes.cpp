class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0, end=0;
        while(start<nums.size()) {
            if(nums[start]) {
                start++;
                continue;
            }
            for(end=max(end, start+1);end<nums.size() && !nums[end];end++);
            if(end>=nums.size())
                break;
            nums[start++]=nums[end];
            nums[end++]=0;
        }
    }
};