class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start=0, end=nums.size()-1;
        int ctr=0;
        while(start<end) {
            if(nums[start]+nums[end]==k) {
                ctr++;
                start++;
                end--;
            }
            else if(nums[start]+nums[end]<k)
                start++;
            else
                end--;
        }
        return ctr;
    }
};