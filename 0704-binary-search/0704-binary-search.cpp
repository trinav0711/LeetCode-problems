class Solution {
private:
    int bin(vector<int>& nums, int t, int left, int right) {
        if(left>right) return -1;
        if(nums[left]==t) return left;
        if(nums[right]==t) return right;
        int mid=(left+right)/2;
        if(nums[mid]==t) return mid;
        if(nums[mid]>t) return bin(nums, t, left, mid-1);
        return bin(nums, t, mid+1, right);
    }
public:
    int search(vector<int>& nums, int target) {
        return bin(nums, target, 0, nums.size()-1);
    }
};