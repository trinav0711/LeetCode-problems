class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int uneq=0;
        for(auto x:nums)
            if(x!=val) ++uneq;
        int start,end,tmp;
        for(start=0,end=nums.size()-1; start<end;){
            if(nums[start]!=val) start++;
            else if(nums[end]==val) end--;
            else{
                swap(nums[start],nums[end]);
                start++;
                end--;
            }
        }
        return uneq;
    }
};