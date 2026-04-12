class Solution {
private:
    
public:
    int findPeakElement(vector<int>& nums, int first=0, int last=INT_MAX) {
        if(nums.size()==1)
            return 0;
        if(last==INT_MAX)
            last=nums.size()-1;
        if(first>=last)
            return -1;
        if(last && nums[first]>nums[first+1]) {
            if(!first || nums[first]>nums[first-1])
                return first;
        }
        if(nums[last]>nums[last-1]) {
            if(last==nums.size()-1 || nums[last]>nums[last+1])
                return last;
        }
        int mid=(first+last)/2;
        if((mid && nums[mid]>nums[mid-1]) && (mid<nums.size()-1 && nums[mid]>nums[mid+1]))
            return mid;
        int tmp=findPeakElement(nums, first, mid-1);
        if(tmp!=-1)
            return tmp;
        return findPeakElement(nums, mid, last-1);
    }
};