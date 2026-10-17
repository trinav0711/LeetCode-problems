class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::function<void(int, int)> func = [&] (int left, int right) {
            if(right-left<1) return;
            if(right-left==1) {
                if(nums[right]<nums[left]) {
                    int tmp=nums[right]; nums[right]=nums[left]; nums[left]=tmp;
                }
                return;
            }
            int mid=(left+right)/2;
            func(left, mid);
            func(mid+1, right);
            vector<int> tmp(right-left+1);
            int i,j1,j2;
            for(i=0, j1=left, j2=mid+1;j1<=mid && j2<=right;++i) {
                tmp[i]=nums[j1]<=nums[j2]?nums[j1++]:nums[j2++];
            }
            if(j1<=mid) {
                while(j1<=mid) tmp[i++]=nums[j1++];
            }
            else {
                while(j2<=right) tmp[i++]=nums[j2++];
            }
            for(i=left;i<=right;++i)
                nums[i]=tmp[i-left];
        };
        func(0, nums.size()-1);
        return nums;
    }
};