class Solution {
    int binsearch(int left, int right, int& t, vector<int>& nums) {
        int mid=(left+right)/2;
        if(t<=nums[left])
            return left;
        if(t>nums[right])
            return right+1;
        if(nums[mid]==t)
            return mid;
        if(left==right)
            return left;
        if(t<nums[mid])
            return binsearch(0, mid, t, nums);
        else
            return binsearch(mid+1, right, t, nums);
        
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return binsearch(0, nums.size()-1, target, nums);
    }
};