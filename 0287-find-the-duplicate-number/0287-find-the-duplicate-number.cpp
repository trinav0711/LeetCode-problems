class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int x:nums) {
            x=abs(x);
            if(nums[x]<0) return x;
            nums[x] *= -1;
        }
        return -1;
    }
};