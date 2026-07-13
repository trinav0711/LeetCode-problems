class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0, end=nums.size()-1;
        int minn=nums[start];
        while(start<end) {
            int mid=(start+end)/2;
            minn=min(minn, nums[mid]);
            minn=min(minn, nums[end]);
            minn=min(minn, nums[mid]);
            if(nums[mid]<nums[end])
                end=mid;
            else
                start=mid+1;
        }
        return minn;
    }
};